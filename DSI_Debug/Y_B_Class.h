#pragma once

#include <vector>

class Y_Point
{
public:
	Y_Point() {};

	int num;
	QString name;
	double x,y,z;
};

class Y_Line
{
public:
	int Flag;
	int	LineNUM;
	Y_Point p1, p2;
};

class Y_Triangle
{
public:
	int TriNum;
	Y_Point p1, p2, p3;
	bool isOverlap;
	int AdjacentTriID_1, AdjacentTriID_2, AdjacentTriID_3;
	int displayOrder;
	int Level;
	int Flag;

	int ID; // 三角形序号
	int nID[3]; // 三角形三个顶点的点号
	double fstNodeX; // 三角形第一个结点坐标
	double fstNodeY;
	double fstNodeZ;
	double sndNodeX; // 三角形第二个结点坐标
	double sndNodeY;
	double sndNodeZ;
	double trdNodeX; // 三角形第三个结点坐标
	double trdNodeY;
	double trdNodeZ;
	std::vector<int>iPassNode; // 三角形上的控制点（点号存储）
};

class YBasePoint
{
public:
	YBasePoint(void) {};
	YBasePoint(int pNumc, double xc, double yc, double zc) {
		pNum = pNumc;
		x = xc;
		y = yc;
		z = zc;
	}
	~YBasePoint() {}

public:
	int pNum;
	double x;
	double y;
	double z;
	double deep;
	int PropertyNum;
	float Property;
	bool operator==(const YBasePoint& p2) {
		if (sqrt(pow((this->x - p2.x), 2) + pow((this->y - p2.y), 2) /*+ pow((this->z - p2.z), 2)*/) < 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:

};

class BasePoly
{
public:
	BasePoly() {};
	~BasePoly() {}
public:

	struct islandstruct
	{
		QString Regionname;
		int RegionNumber;
		double xmin;
		double ymin;
		double zmin;
		double xmax;
		double ymax;
		double zmax;
		QString IslandNum;
		QList<YBasePoint>polylist;
	};
	QString Regionname;
	int RegionNumber;
	double xmin;
	double ymin;
	double zmin;
	double xmax;
	double ymax;
	double zmax;
	YBasePoint avepoint;
	QString IslandNum;
	QList<YBasePoint>polylist;
	QList<islandstruct>IslandPoly;
};

class wxlvertec {
public:
	wxlvertec(double tx, double ty, double tz) {
		x = tx;
		y = ty;
		z = tz;
	};
	~wxlvertec() {}
public:
	double x, y, z;

};