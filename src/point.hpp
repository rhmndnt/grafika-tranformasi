#ifndef _POIN_H
#define _POIN_H


class point {
public:
	point();
	point(int x, int y);
	point(const point& p);

	// Setter and getter
	int get_x() const;
	int get_y() const;
	void set_x(int x);
	void set_y(int y);
	void set_coord(int x, int y);

	// Comparator function
	static bool cmp_x(const point& p1, const point& p2);
	static bool cmp_y(const point& p1, const point& p2);

	// Transformasi
	point scale(float scale);
	point move(int delta_x = 0, int delta_y = 0);
private:
	int x;
	int y;
};

#endif
