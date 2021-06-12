#include <huw.hpp>

extern huw::sprite abfall;


bool huw::collision(huw::sprite& a, huw::sprite& b)
{
	if(	a.dst_rect.x < b.dst_rect.x+b.dst_rect.w &&
		a.dst_rect.x+a.dst_rect.w > b.dst_rect.x &&
		a.dst_rect.y < b.dst_rect.y+b.dst_rect.h &&
		a.dst_rect.y+a.dst_rect.h > b.dst_rect.y)
	{
		return true;
	}
	return false;
}

bool huw::coll_up(huw::sprite& a){
	if(a.acc.y<0){
		if(collision(a, abfall)){
			return false;
		}
	}
	return true;
}

bool huw::coll_down(huw::sprite& a){
	if(a.acc.y>0){
		if(collision(a, abfall)){
			return false;
		}
	}
	return true;
}

bool huw::coll_right(huw::sprite& a){
	if(a.acc.x>0){
		if(collision(a, abfall)){
			return false;
		}
	}
	return true;
}

bool huw::coll_left(huw::sprite& a){
	if(a.acc.x<0){
		if(collision(a, abfall)){
			return false;
		}
	}
	return true;
}

bool huw::coll_all(huw::sprite& a){
	if(coll_up(a) && coll_down(a) && coll_right(a) && coll_left(a)){
		return true;
	}
	return false;
}