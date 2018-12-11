#include "LimitTransparent.h"

void CLimit::LoadResource()
{

}

void CLimit::Render(float xViewport, float yViewport)
{
	this->X_view = x - xViewport;
	this->Y_view = y - yViewport;

	RenderBoundingBox();
}

void CLimit::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	l = x;
	t = y;
	switch (this->state)
	{
		case LIMIT_CAMERA:
		{
			r = x + LIMITCAM_BBOX_WIDTH;
			b = y + LIMITCAM_BBOX_HEIGHT;
			break;
		}

		case LIMIT_GROUND:
		{
			r = x + LIMIT_GROUND_WIDTH * widthBBox;
			b = y + LIMIT_GROUND_HEIGHT * heightBBox;
			break;
		}

		default:
		{
			r = x + LIMIT_GROUND_WIDTH * widthBBox;
			b = y + LIMIT_GROUND_HEIGHT * heightBBox;
			break;
		}
	}


}
