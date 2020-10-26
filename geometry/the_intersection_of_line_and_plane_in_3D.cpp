#include <iostream>

using namespace std;

//三维坐标点
struct Point3D 
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
};

//在三维空间中,计算直线和平面的交点坐标
//参数解释:
//Point3D lp:Line Point,直线上的某一点
//Point3D lv:Line Vector,直线的方向向量
//Point3D pp:Plane Point,平面上的某一点
//Point3D pv:Plane Vector,平面的法向量
Point3D InterectionLinePlane3D(Point3D lp, Point3D lv, Point3D pp, Point3D pv)
{
	Point3D pnt;
	//判断直线是否与平面平行
	double n = lv.x * pv.x + lv.y * pv.y + lv.z * pv.z;
	if (fabs(n) < DBL_EPSILON)
	{
		cout << "Warning:The line is parallel to the plane!" << endl;
		return pnt;
	}
	else
	{
		double m = ((pp.x - lp.x) * pv.x + (pp.y - lp.y) * pv.y + (pp.z - lp.z) * pv.z) / n;
		pnt.x = lp.x + lv.x * m;
		pnt.y = lp.y + lv.y * m;
		pnt.z = lp.z + lv.z * m;
		return pnt;
	}
}


int main()
{
	//例子1:
	//直线与平面平行
	Point3D pnt1, pnt2, pnt3, pnt4, pnt_result1;
	pnt1.z = 1.0;
	pnt2.y = 1.0;
	pnt4.z = 1.0;
	pnt_result1 = InterectionLinePlane3D(pnt1, pnt2, pnt3, pnt4);

	//例子2:
	//直线方程:x+1=y-3=z/2
	//平面方程:3x-4y+z-1=0
	//交点坐标(15,19,32)
	Point3D pnt5, pnt6, pnt7, pnt8, pnt_result2;
	pnt5.x = -1.0;
	pnt5.y = 3.0;
	pnt6.x = pnt6.y = 1.0;
	pnt6.z = 2;
	pnt7.z = 1.0;
	pnt8.x = 3.0;
	pnt8.y = -4.0;
	pnt8.z = 1.0;
	pnt_result2 = InterectionLinePlane3D(pnt5, pnt6, pnt7, pnt8);

	return 0;
}