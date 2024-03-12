#pragma once

#include <QObject>
#include"Y_B_Class.h"
#include<qmath.h>
#include<qdebug.h>

class BasicAlgorithm : public QObject
{
	Q_OBJECT

public:
	BasicAlgorithm() {};
	BasicAlgorithm(QObject *parent);
	~BasicAlgorithm();

public:
	//�жϵ��ڶ������
	//�жϵ���Բ��
	bool FilterPoint_in_circle(YBasePoint _P, YBasePoint _Center,double radius);

	//����dem
	QList<YBasePoint>GetTopDem(YBasePoint _pmax, YBasePoint _pmin, double delta);

	//��ȡ����������
	QList<int>getRowColumn(QList<YBasePoint>_list);

	//����͹��
    /*���� �����ƽ�����*/
	double xjGet2DistancePP(YBasePoint p1, YBasePoint p2) { return (sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y))); }
	/*���� ���������Ĳ����p0�ǹ����㣩*/
	double xjGetCrossProduct(YBasePoint p1, YBasePoint p2, YBasePoint p0) { return ((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y)); }
	/*���� ͹���ı߽������*/
	QList<YBasePoint>xjGetConvexHullByGrahamScan(QList<YBasePoint> listPoint);

	/*�жϵ��ڶ������*/
	bool isPoint_in_Poly(YBasePoint&ptemp, BasePoly&mPoly);
	int pointxRayPoly(YBasePoint&myPoint, BasePoly&myPoly);
	bool pointInLine(YBasePoint p, YBasePoint p1, YBasePoint p2);
	double twoDLenPointToLine(YBasePoint&p, YBasePoint&p1, YBasePoint&p2);
	double computeX(double x1, double y1, double x2, double y2, double y);

	//IDW��ֵ
	void IDWInsert(YBasePoint&_p, QList<YBasePoint>&_knowPoints);
	void SelectNearPoints(YBasePoint&p1, QList<double>& _nearDistances, QList<YBasePoint>& _nearpoints, QList <YBasePoint>&_NownPoints);
};

void deleteDuplicatePoint(QList<YBasePoint>&_list);