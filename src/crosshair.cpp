#include "crosshair.hpp"
#include <iostream>

crosshair::crosshair() {
	this->outline_scale = 1;
	this->rotate_factor = 0;
	x_pos = 50;
	y_pos = 50;
	// vertical line
	lines.add(line(9,0,9,6));
	lines.add(line(9,12,9,18));
	lines.add(line(4,4,4,14));
	lines.add(line(14,4,14,14));
	// horizontal line
	lines.add(line(0,9,6,9));
	lines.add(line(12,9,18,9));
	lines.add(line(4,4,14,4));
	lines.add(line(4,14,14,14));
}

void crosshair::draw_stroke(uint32_t color) {
	draw_vertical();
	draw_horizontal();
}

void crosshair::reset() {
	points.clear();
}

void crosshair::scaleOutline(float outline_scale) {
	if (outline_scale > 0)
			this->outline_scale = outline_scale;
}

void crosshair::scale(float scale) {
	//this->scale_factor = scale;
	for (int i = 0; i < lines.size() - 1; i++) {
		lines[i].scale(scale);
	}
}

void crosshair::rotate(float rotate) {
	this->rotate_factor = rotate;
}

void crosshair::setX(int x) {
	this->x_pos = x;
}

void crosshair::setY(int y) {
	this->y_pos = y;
}

void crosshair::moveX(int dx) {
	this->x_pos += dx;
}

void crosshair::moveY(int dy) {
	this->y_pos += dy;
}

void crosshair::draw_vertical() {
	for (int i = 0; i < 4; i++) {
		lines[i].move(x_pos/2, y_pos/2);
		lines[i].move(scale_factor - 1, 0);
		lines[i].draw();
		if (scale_factor > 1) {
			for (int j = 0; j < (scale_factor - 1) * 2; j++) {
				lines[i].move(-1, 0);
				lines[i].draw();
			}	
		}
	}
}

void crosshair::draw_horizontal() {
	for (int i = 4; i < 8; i++) {
		lines[i].move(x_pos/2, y_pos/2);
		lines[i].move(0, scale_factor - 1);
		lines[i].draw();
		if (scale_factor > 1) {
			for (int j = 0; j < (scale_factor - 1) * 2; j++) {
				lines[i].move(0, -1);
				lines[i].draw();
			}	
		}
	}
}