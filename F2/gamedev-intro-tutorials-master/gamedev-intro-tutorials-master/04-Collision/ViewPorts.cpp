#include "ViewPorts.h"

CView::CView(float x_cam, float y_cam)
{
	pos_cam.x = x_cam;
	pos_cam.y = y_cam;
	pos_cam.z = 0;
}

CView::~CView()
{

}

D3DXVECTOR3 CView::SetPositionInCamera(D3DXVECTOR3 pos_W)
{
	D3DXVECTOR3 pos_change;
	pos_change.x = pos_W.x - pos_cam.x;
	pos_change.y = pos_W.y - pos_cam.y;
	pos_change.z = 0;

	return pos_change;
}

void CView::SetPositionCamera(float x, float y)
{
	pos_cam.x = x;
	pos_cam.y = y;
	pos_cam.z = 0;
}

D3DXVECTOR3 CView::GetPositionCamera()
{
	return this->pos_cam;
}
