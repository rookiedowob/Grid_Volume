//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//##########                 时间：2022年11月3日                    #########
//##########                 项目类型： 课程作业                    #########
//##########                  规则格网计算体积                      #########
//##########                 编写平台：C++ 、QT                     #########
//# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

#include "Grids_V.h"
#include "Y_B_Class.h"

#include <qstring.h>
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>
#include <qmessagebox.h>
#include <qfile.h>
#include <string>
#include <vector>
#include <qtextdocument.h>
#include <QTextBlock>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include <process.h>
#include <qfiledialog.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <qprogressbar.h>
#include <qprogressdialog.h>
#include <qmath.h>
#include <iostream>
#include <fstream>

#include<Windows.h>
#include<shellapi.h>
#pragma comment(lib,"Shell32.lib")

std::vector<QString>FilePaths;

std::vector<Y_Point> KZPList; // 控制点位
std::vector<Y_Point> PList; // 
std::vector<Y_Point> GridsPList; // 规则格网
std::vector<YBasePoint> ZXPList; // 格网中心点位
std::vector<YBasePoint> INZXPlist; // 在凸包内的网格中心点位
std::vector<Y_Triangle> TList;
std::vector<Y_Triangle> TTList;
QList<YBasePoint> Vpoint; // 构建地质体的点集

QList<YBasePoint> list1; // 
QList<YBasePoint> list2; // 控制点列表，同KZPlist
std::string filepath = "points.txt";
int Gstep = 80; // 网格步长
BasePoly poly1; // 多边形
BasicAlgorithm B;

Grids_V::Grids_V(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	this->showMaximized();
	connect(ui.open, SIGNAL(triggered(bool)), this, SLOT(on_open_clicked()));
	connect(ui.close, SIGNAL(triggered(bool)), this, SLOT(on_close_clicked()));
	connect(ui.showmodel, SIGNAL(triggered(bool)), this, SLOT(Showpointset()));
	connect(ui.ConvexPack, SIGNAL(triggered(bool)), this, SLOT(MMM()));
	connect(ui.clear, SIGNAL(triggered(bool)), this, SLOT(on_clear_clicked()));
	connect(ui.GridsView, SIGNAL(triggered(bool)), this, SLOT(CreateGrids()));
	connect(ui.action2, SIGNAL(triggered(bool)), this, SLOT(CreateGrids1()));
	connect(ui.actionisinpoly, SIGNAL(triggered(bool)), this, SLOT(G_IN_Poly()));
	connect(ui.actionIDW, SIGNAL(triggered(bool)), this, SLOT(on_IDW_clicked()));
}

// 打开文件
void Grids_V::on_open_clicked()
{
	QString filename;
	QString curpath = QDir::currentPath();
	std::string title = "打开一个文件";
	std::string filter = "原始点位文件(*.txt);;所有文件(*.*)";
	QString afilename = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("打开一个文件"), curpath, QString::fromLocal8Bit("原始点位文件(*.txt);;所有文件(*.*)"));
	file_path_ = afilename;
	if (afilename.isEmpty())return;
	filepath = afilename.toStdString();

	// 读取数据
	this->Readfile(filepath);

	// 读取数据的可视化
	for (int i = 0; i < KZPList.size(); i++)
	{
		YBasePoint p;
		p.x = KZPList[i].x;
		p.y = KZPList[i].y;
		p.z = KZPList[i].z;
		KZPList[i].num = i + 1;
		p.pNum = i + 1;
		list2.append(p);
	}
	QString str = QString("%1").arg(list2.size()) + QString::fromLocal8Bit(" 个");
	ui.label6->setText(str);
	QMessageBox::about(this, QStringLiteral("提示！"), QStringLiteral("成功打开文件!"));
	
	update();
	return;
}
// 清空窗口
void Grids_V::on_clear_clicked()
{
	list1.clear();
	list2.clear();
	KZPList.clear(); // 控制点
	GridsPList.clear(); // 规则格网
	ZXPList.clear(); // 格网中心点
	INZXPlist.clear(); // 在凸包内的格网中心点
	poly1.polylist.clear(); // 凸包多边形
	ui.label->clear();
	ui.label6->clear();
	ui.label7->clear();
	ui.label4->clear();
	update();
}
// 反距离加权插值
void Grids_V::on_IDW_clicked()
{	
	// 利用格网的中心点位来进行插值计算
	// 用于计算体积的点位数组
	QList<YBasePoint> VKZpoint;
	double V = 0;
	// 存储控制点坐标
	for (int i = 0; i < KZPList.size(); i++)
	{
		YBasePoint temp1;
		temp1.x = KZPList[i].x;
		temp1.y = KZPList[i].y;
		temp1.z = KZPList[i].z;
		temp1.pNum = KZPList[i].num;
		VKZpoint.append(temp1);
	}

	// 初始化参数
	Vpoint.clear();
	INZXPlist.clear();
	// 插值计算中心点坐标
	for (int i = 0; i < ZXPList.size(); i++)
	{
		YBasePoint temp2;
		temp2.x = ZXPList[i].x;
		temp2.y = ZXPList[i].y;
		temp2.z = ZXPList[i].z;
		B.IDWInsert(temp2, VKZpoint);
		Vpoint.append(temp2);
		if (B.isPoint_in_Poly(temp2, poly1))
		{
			INZXPlist.push_back(temp2);
		}
	}
	// 输出插值计算的点位
	std::ofstream outfile("out.txt", std::ios::trunc);
	for (int i = 0; i < INZXPlist.size(); i++)
	{
		outfile << INZXPlist[i].x << "," << INZXPlist[i].y << "," << INZXPlist[i].z <<"\n";
	}
	// myfile.close();
	outfile.close();

	// 计算体积
	for (int i = 0; i < INZXPlist.size(); i++)
	{
		V += Gstep * Gstep * INZXPlist[i].z / 100;
	}
	
	// 将计算的体积进行显示
	QString str = QString("%1").arg(V) + " m^3";
	ui.label->setText(str);
	ui.label->show();
	update();
}
// 关闭窗口
void Grids_V::on_close_clicked()
{
	// 关闭窗口
	this->close();
}
// 展示三维模型
void Grids_V::Showpointset()
{
	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
	ShellExecute(NULL, TEXT("open"), TEXT("E:\\applications\\QT_projects\\Grids_V\\DSI_Debug\\Grids.mlp"), NULL, NULL, SW_SHOWNORMAL);
}
// 创建规则格网
void Grids_V::CreateGrids()
{
	// 生成规则格网
	Y_Point PTemp;
	double a, b;
	int Gstep = 80; // 网格步长
	for (int i = 0; i < 22; i++)
	{
		a = 110 + i * Gstep;
		for (int j = 0; j < 11; j++)
		{
			b = 120 + j * Gstep;

			PTemp.x = a;
			PTemp.y = b;
			GridsPList.push_back(PTemp);
		}
	}
	// 提取网格中心点
	for (int i = 0; i < GridsPList.size() - 11; i++)
	{
		// 中心点点位信息
		Y_Point ptemp;
		ptemp.x = GridsPList[i].x + Gstep / 2;
		ptemp.y = GridsPList[i].y + Gstep / 2;
		ptemp.num = GridsPList[i].num;
		ptemp.z = 0;

		// 特殊情况标记
		if ((i + 1) % 11 != 0) {
			have++;
			YBasePoint pp; // 暂时存储点的信息
			pp.x = ptemp.x;
			pp.y = ptemp.y;
			pp.pNum = have;
			ZXPList.push_back(pp);
		}
	}
	QString str = QString("%1").arg(ZXPList.size()) + QString::fromLocal8Bit(" 个");
	ui.label4->setText(str);
	update();
}
// 加密规则格网
void Grids_V::CreateGrids1()
{
	// 生成规则格网
	Y_Point PTemp;
	double a, b;
	int Gstep = 40; // 网格步长
	for (int i = 0; i < 44; i++)
	{
		a = 110 + i * Gstep;
		for (int j = 0; j < 22; j++)
		{
			b = 120 + j * Gstep;

			PTemp.x = a;
			PTemp.y = b;
			GridsPList.push_back(PTemp);
		}
	}
	// 提取网格中心点
	for (int i = 0; i < GridsPList.size() - 44; i++)
	{
		// 中心点点位信息
		Y_Point ptemp;
		ptemp.x = GridsPList[i].x + Gstep / 2;
		ptemp.y = GridsPList[i].y + Gstep / 2;
		ptemp.num = GridsPList[i].num;
		ptemp.z = 0;

		// 特殊情况标记
		if ((i + 1) % 22 != 0) {
			have++;
			YBasePoint pp; // 暂时存储点的信息
			pp.x = ptemp.x;
			pp.y = ptemp.y;
			pp.pNum = have;
			ZXPList.push_back(pp);
		}
	}
	QString str = QString("%1").arg(ZXPList.size()) + QString::fromLocal8Bit(" 个");
	ui.label4->setText(str);
	update();
}
// 判断点在多边形内
void Grids_V::G_IN_Poly()
{
	// 创建边界多边形的最小包尾框
	YBasePoint pmax(-1, -9999999, -9999999, -999999);
	YBasePoint pmin(-1, 9999999, 9999999, 999999);
	for (int i = 0; i < list1.size(); i++)
	{
		pmax.x = qMax(pmax.x, list1[i].x); pmax.y = qMax(pmax.y, list1[i].y);
		pmin.x = qMin(pmin.x, list1[i].x); pmin.y = qMin(pmin.y, list1[i].y);
		poly1.xmax = pmax.x; poly1.xmin = pmin.x;
		poly1.ymax = pmax.y; poly1.ymin = pmin.y;

	}

	// 点在多边形内判断并标记
	for (int i = 0; i < ZXPList.size(); i++)
	{
		if (B.isPoint_in_Poly(ZXPList[i], poly1))
		{
			INZXPlist.push_back(ZXPList[i]);
		}
	}
	QString str = QString("%1").arg(INZXPlist.size()) + QString::fromLocal8Bit(" 个");
	ui.label7->setText(str);
	update();
}
// 绘制凸包
void Grids_V::MMM()
{
	list1.clear();
	poly1.polylist.clear();
	list1 = B.xjGetConvexHullByGrahamScan(list2);

	// 边界多边形
	poly1.xmax = poly1.xmin = list1[0].x;
	poly1.ymax = poly1.ymin = list1[0].y;
	for (int i = 0; i < list1.size(); i++)
	{
		poly1.polylist.append(list1[i]);

	}
	poly1.polylist.append(list1[0]);
	update();
}
// 可视化
void Grids_V::paintEvent(QPaintEvent*)
{
	// 格网画笔
	QPainter painter(this); // painter 只声明一次
	QPen pen(QColor(255, 0, 0)); // pen 可以生成多个
	pen.setWidth(4);
	painter.setPen(pen);
	QBrush brush(QColor(0, 255, 0));

	// 规则格网的可视化
	if (GridsPList.size() != 0)
	{
		for (int i = 0; i < GridsPList.size(); i++)
		{
			// 绘制网格结点
			painter.drawPoint(GridsPList[i].x, GridsPList[i].y);
			// 绘制网格
			for (int j = 0; j < GridsPList.size(); j++)
			{
				if (Dist(GridsPList[i].x, GridsPList[j].x, GridsPList[i].y, GridsPList[j].y) == 0)
				{
					continue;
				}
				else if (Dist(GridsPList[i].x, GridsPList[j].x, GridsPList[i].y, GridsPList[j].y) == Gstep)
				{
					painter.drawLine(QPoint(GridsPList[i].x, GridsPList[i].y), QPoint(GridsPList[j].x, GridsPList[j].y));
				}
				continue;
			}
		}
	}

	// 规则格网中心点可视化
	if (ZXPList.size() != 0)
	{
		for (int i = 0; i < ZXPList.size(); i++)
		{
			painter.drawPoint(ZXPList[i].x, ZXPList[i].y);
		}
	}

	// 设置画笔属性
	QPen pen2(QColor(0, 255, 0));
	pen2.setWidth(8);
	painter.setPen(pen2);

	// 绘制原始数据
	if (KZPList.size() != 0)
	{
		for (int i = 0; i < KZPList.size(); i++)
		{
			painter.drawPoint(KZPList[i].x, KZPList[i].y);
		}
		
	}
	// 绘制凸包多边形
	if (poly1.polylist.size() != 0)
	{
		for (int i = 0; i < poly1.polylist.size()-1; i++)
		{
			painter.drawLine(QPoint(poly1.polylist[i].x, poly1.polylist[i].y), QPoint(poly1.polylist[i + 1].x, poly1.polylist[i + 1].y));
		}
	}

	// 点在多边形内判断并绘制
	if (INZXPlist.size() != 0)
	{
		QPen pen3(QColor(255, 255, 0));
		pen3.setWidth(8);
		painter.setPen(pen3);
		for (int i = 0; i < INZXPlist.size(); i++)
		{
			painter.drawPoint(INZXPlist[i].x, INZXPlist[i].y);
		}
	}
}
// 输出三维模型
void Grids_V::Creatbody()
{
	for (int i = 0; i < ZXPList.size(); i++)
	{
		YBasePoint temp3;
		temp3.x = ZXPList[i].x;
		temp3.y = ZXPList[i].y;
		temp3.z = ZXPList[i].z;
		Vpoint.append(temp3);
	}
	// 插值生成地质体
	std::ofstream F1;//输出
	int ccount = 0;
	F1.open("ZSyurf.obj", std::ios::out);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	F1 << "ZSyurf.obj\n";
	F1 << "#" << '\n' << "# " << "ZSyurf.obj" << '\n' << "#" << '\n';
	for (int i = 0; i < Vpoint.size(); i++)
	{
		F1 << "v " << Vpoint[i].x << " " << Vpoint[i].y << " " << Vpoint[i].z << "\n";
		ccount++;
	}
	F1 << "# " << ccount << " verticles\n" << "\n";
	F1.close();
}
// 读数据
void Grids_V::Readfile(std::string path)
{
	// 读取文件函数
	KZPList.clear();
	std::vector <double> temp;
	Y_Point ptemp;
	int ch;
	std::ifstream fin;
	fin.clear();
	fin.open(path);

	for (int i = 0; !fin.eof(); i++) {
		fin >> ch;
		temp.push_back(ch);
		fin.get();
	}
	fin.close();

	for (int i = 0; i < temp.size() / 3; i++)
	{
		ptemp.x = temp[3 * i];
		ptemp.y = temp[3 * i + 1];
		ptemp.z = temp[3 * i + 2];
		KZPList.push_back(ptemp);
	}
}
// 计算几何距离
double Grids_V::Dist(double a, double b, double c, double d)
{
	// 两点之间的距离
	double dist = sqrt((a - b) * (a - b) + (c - d) * (c - d));
	return dist;
}