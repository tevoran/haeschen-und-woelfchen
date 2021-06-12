#include <huw.hpp>


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