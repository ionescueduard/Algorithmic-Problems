#include <iostream>
#include <queue>

using namespace std;

#define ROW 9 
#define COL 10

#define UP     [y-1][x]
#define DOWN   [y+1][x]
#define LEFT   [y][x-1]
#define RIGHT  [y][x+1]

class Point
{
public:
	int y;
	int x;

	Point(int y=0, int x=0) : y(y), x(x) {};

	bool operator==(const Point& p) const
	{
		return x == p.x && y == p.y;
	}
}; 

bool inBounds(Point p) {
	return p.x > -1 && p.x < COL && p.y > -1 && p.y < ROW;
}

int findShortestPath(int m[ROW][COL], Point source, Point destination)
{
	Point bounds[4] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
	Point curr;
	queue<Point> q;
	q.push(source);
	m[source.y][source.x] = 0;

	while (!q.empty())
	{
		curr = q.front(); q.pop();
		for (Point bound : bounds)
		{
			Point neighbour(curr.y + bound.y, curr.x + bound.x);

			if (neighbour == destination) return m[curr.y][curr.x] + 1;

			if (inBounds(neighbour))
			{
				if (m[neighbour.y][neighbour.x] == -1) {
					m[neighbour.y][neighbour.x] = m[curr.y][curr.x] + 1;
					q.push(Point(neighbour.y, neighbour.x));
				}
			}
		}
	}

	return -1;
}

int main2()
{
	int mat[ROW][COL] =
	{
		{ -1, 0, -1, -1, -1, -1, 0, -1, -1, -1 },
		{ -1, 0, -1, 0, -1, -1, -1, 0, -1, -1 },
		{ -1, -1, -1, 0, -1, -1, 0, -1, 0, -1 },
		{ 0, 0, 0, 0, -1, 0, 0, 0, 0, -1 },
		{ -1, -1, -1, 0, -1, -1, -1, 0, -1, 0 },
		{ -1, 0, -1, -1, -1, -1, 0, -1, 0, 0 },
		{ -1, 0, 0, 0, 0, 0, 0, 0, 0, -1 },
		{ -1, 0, -1, -1, -1, -1, 0, -1, -1, -1 },
		{ -1, -1, 0, 0, 0, 0, -1, 0, 0, -1 }
	};

	Point source(0, 0);
	Point dest(3, 4);

	std::cout << findShortestPath(mat, source, dest);

	getchar();
	return 0;
}