#include "BasicAlgorithm.h"

BasicAlgorithm::BasicAlgorithm(QObject *parent)
	: QObject(parent)
{
}

BasicAlgorithm::~BasicAlgorithm()
{
}

bool BasicAlgorithm::FilterPoint_in_circle(YBasePoint _P, YBasePoint _Center, double radius)
{
	// return false;
	double dis = 0;
	dis = qSqrt(qPow(_P.x - _Center.x, 2) + qPow(_P.y - _Center.y, 2));
	if (dis - radius <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

QList<YBasePoint> BasicAlgorithm::GetTopDem(YBasePoint _pmax, YBasePoint _pmin, double delta)
{
	QList<YBasePoint>_list;
	int numx = qAbs(_pmax.x - _pmin.x) / delta + 1;
	int numy = qAbs(_pmax.y - _pmin.y) / delta + 1;
	int numz = qAbs(_pmax.z - _pmin.z) / delta + 1;
	int knowPointNum = 0;
	if (knowPointNum != 0)
	{

	}
	else
	{
		for (int i = 0; i < numx; i++)
		{
			for (int j = 0; j < numy; j++)
			{

				double x0 = _pmin.x /*- gridLen / 2*/ + i * delta;
				double y0 = _pmin.y /*- gridLen / 2*/ + j * delta;
				YBasePoint tt;
				tt.x = x0;
				tt.y = y0;
				tt.z = _pmax.z;
				_list.append(tt);
				
			}
		}
	}
	return _list;
}

QList<int> BasicAlgorithm::getRowColumn(QList<YBasePoint> _list)
{
	QList<int>_RowColumn;
	double xflag = -1;
	double yflag = -1;
	int row = 0;
	int column = 0;
	for (int i = 0; i < _list.size(); i++)
	{
		if (xflag != _list[i].x)
		{
			column++;
			xflag = _list[i].x;
			row = i + 1;
		}
	}
	_RowColumn.append(row);
	_RowColumn.append(column);

	return _RowColumn;
}

QList<YBasePoint> BasicAlgorithm::xjGetConvexHullByGrahamScan(QList<YBasePoint> listPoint)
{
	QList<YBasePoint> xjListResult;

	int i = 0, j = 0, k = 0;
	YBasePoint tmP = listPoint[0];

	//排序 找到最下且偏左的点
	for (i = 1; i < listPoint.size(); i++)
	{
		if ((listPoint[i].y < tmP.y) || ((listPoint[i].y == tmP.y) && (listPoint[i].x < tmP.x)))
		{
			tmP = listPoint[i];
			k = i;
		}
	}
	listPoint[k] = listPoint[0];
	listPoint[0] = tmP;

	//排序 按极角从小到大，距离从近到远 
	for (i = 1; i < listPoint.size(); i++)
	{
		k = i;
		for (j = i + 1; j < listPoint.size(); j++)
		{
			double cross = xjGetCrossProduct(listPoint[j], listPoint[k], listPoint[0]);
			double disance_j = xjGet2DistancePP(listPoint[0], listPoint[j]);
			double disance_k = xjGet2DistancePP(listPoint[0], listPoint[k]);
			if ((cross > 0) || ((cross == 0) && (disance_j < disance_k)))
			{
				k = j;//k保存极角最小的那个点,或者相同距离原点最近
			}
		}
		tmP = listPoint[i];
		listPoint[i] = listPoint[k];
		listPoint[k] = tmP;
	}

	//添加第一、二个凸包点
	xjListResult.append(listPoint[0]);
	xjListResult.append(listPoint[1]);

	//遍历
	for (i = 2; i < listPoint.size(); ++i)
	{
		for (j = i + 1; j < listPoint.size(); ++j)
		{
			if (xjGetCrossProduct(listPoint[i], listPoint[j], xjListResult[xjListResult.size() - 1]) < 0)
			{
				i = j;
			}
		}
		xjListResult.append(listPoint[i]);
	}

	return xjListResult;
}

bool BasicAlgorithm::isPoint_in_Poly(YBasePoint& ptemp, BasePoly& mPoly)
{
	int flag = 0;
	int midflag = pointxRayPoly(ptemp, mPoly);
	if (midflag == -1)
	{
		return false;
	}
	flag += midflag;////不位于弧段上，加上相应的交点数目
	if (flag % 2 == 1)
	{
		return true;
	}
}

int BasicAlgorithm::pointxRayPoly(YBasePoint& myPoint, BasePoly& myPoly)
{
	if (myPoint.x <= myPoly.xmin || myPoint.y <= myPoly.ymin || myPoint.y >= myPoly.ymax||myPoint.x>=myPoly.xmax)
	{
		return 0;////射线没有交点
	}
	int numPoint = myPoly.polylist.size();	////多段线点数
	int flag1, flag2;
	for (int i = 0; i < numPoint - 1; i++)
	{
		flag1 = i;
		flag2 = i + 1;
		if (pointInLine(myPoint, myPoly.polylist.at(flag1), myPoly.polylist.at(flag2)))
		{
			return -1;
		}
	}
	int flag = 0;
	for (int i = 0; i < numPoint - 1; i++)
	{
		flag1 = i;
		flag2 = i + 1;
		YBasePoint mp1 = myPoly.polylist.at(flag1);
		YBasePoint mp2 = myPoly.polylist.at(flag2);
		if (abs(myPoly.polylist.at(flag1).y - myPoint.y) < 0.0001)
		{
			if (myPoly.polylist.at(flag1).x - myPoint.x < 0.0001 && qAbs(myPoly.polylist[flag2].y - myPoint.y) < 0.0001)
			{
				flag++;
			}
			continue;
		}
		if (abs(myPoly.polylist[flag2].y - myPoint.y) < 0.0001)
		{
			if (myPoly.polylist[flag1].x - myPoint.x < 0.0001 &&qAbs(myPoly.polylist[flag2].y - myPoint.y) < 0.0001)
			{
				flag++;
			}
			continue;
		}
		if ((myPoly.polylist[flag1].y - myPoint.y)*(myPoly.polylist[flag2].y - myPoint.y) < 0)
		{
			if (computeX(myPoly.polylist[flag1].x, myPoly.polylist[flag1].y, myPoly.polylist[flag2].x, myPoly.polylist[flag2].y, myPoint.y) < myPoint.x)
			{
				flag++;
				continue;
			}
		}
	}
	return flag;
}

bool BasicAlgorithm::pointInLine(YBasePoint p, YBasePoint p1, YBasePoint p2)
{
	if (twoDLenPointToLine(p, p1, p2) < 1)
	{
		return true;
	}
	return false;
}

double BasicAlgorithm::twoDLenPointToLine(YBasePoint& p, YBasePoint& p1, YBasePoint& p2)
{
	wxlvertec v1 = wxlvertec(p2.x - p1.x, p2.y - p1.y, 0);
	wxlvertec v2 = wxlvertec(p.x - p1.x, p.y - p1.y, 0);

	double t = v1.x * v2.x + v1.y * v2.y;	////点乘

	if (t <= 0)
	{
		return sqrt(v2.x * v2.x + v2.y * v2.y);
	}

	double DdD = v1.x * v1.x + v1.y * v1.y;

	if (t >= DdD)
	{
		wxlvertec v3 = wxlvertec(p.x - p2.x, p.y - p2.y, 0);

		return sqrt(v3.x * v3.x + v3.y * v3.y);
	}

	double len = v2.x * v2.x + v2.y * v2.y - t * t / DdD;

	if (len < 0)
	{
		return 0.0;
	}

	return sqrt(len);
}

double BasicAlgorithm::computeX(double x1, double y1, double x2, double y2, double y)
{
	if (qAbs(x1 - x2) < 0.0001 || qAbs(y1 - y2) < 0.0001)
	{
		return x1;
	}
	else
	{
		return (y - y1) / (y2 - y1)*(x2 - x1) + x1;
	}
}

// 两个参数 待插值的点，已知点链表
void BasicAlgorithm::IDWInsert(YBasePoint& _p, QList<YBasePoint>& _knowPoints)
{
	QList<YBasePoint>nearPoints; // 附近点
	QList<double>nearDistances; // 附近点距离
	SelectNearPoints(_p, nearDistances, nearPoints, _knowPoints); // 选择附近点
	double sum = 0;
	double z = 0;
	for (int d = 0; d < nearDistances.size(); d++)
	{
		if (nearDistances.at(d) != 0)
		{
			double inv = 1 / nearDistances.at(d);
			sum += qPow(inv, 2);
		}
		else
		{
			break;
		}
	}
	//每个点的权重并插值
	for (int d = 0, n = 0; d < nearDistances.size(); d++, n++)
	{
		if (nearDistances.at(d) != 0)
		{
			double inv = 1 / nearDistances.at(d);
			double weight = qPow(inv, 2) / sum;
			z += nearPoints.at(n).z*weight;
		}
		else
		{
			z = nearPoints.at(n).z;
			break;
		}
	}
	_p.z = z;
}

void BasicAlgorithm::SelectNearPoints(YBasePoint& p1, QList<double>& _nearDistances, QList<YBasePoint>& _nearpoints, QList<YBasePoint>& _NownPoints)
{
	double mDistance;
	QList<double>mDistinceList;
//#pragma omp parallel
//	{
//#pragma omp for
		for (int i = 0; i < _NownPoints.size(); i++)
		{
			mDistance = qSqrt(qPow(p1.x - _NownPoints.at(i).x, 2) + qPow(p1.y - _NownPoints.at(i).y, 2));
			mDistinceList.append(mDistance);
		}
//	}

	QList<double>distanceSet;
	distanceSet = mDistinceList;
	qSort(distanceSet.begin(), distanceSet.end());

	int _pointindex;
	for (int i = 0; i < 5; i++)
	{
		_pointindex = mDistinceList.indexOf(distanceSet.at(i));
		_nearpoints.append(YBasePoint(-50, _NownPoints.at(_pointindex).x, _NownPoints.at(_pointindex).y, _NownPoints.at(_pointindex).z));
		_nearDistances.append(distanceSet.at(i));
	}
}

void deleteDuplicatePoint(QList<YBasePoint>& _list)
{
	int numPoints = _list.size();
	for (int i = 0; i < numPoints; i++)
	{
		for (int j = i + 1; j < numPoints; j++)
		{
			if (_list[i] == _list[j])
			{
				_list.removeAt(j);
				j--; numPoints--;
			}
		}
	}
}
