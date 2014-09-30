#pragma once


// CHeaderCtrlEx

class CHeaderCtrlEx : public CHeaderCtrl
{
	DECLARE_DYNAMIC(CHeaderCtrlEx)

protected:
	DECLARE_MESSAGE_MAP()

public:
	CHeaderCtrlEx();
	virtual ~CHeaderCtrlEx();

	afx_msg void OnPaint();
	CStringArray m_HChar;
	CString m_Format; //��ʾ�������͵���������,0��ʾ����룬1��ʾ�м���룬2��ʾ�Ҷ���

	int m_R;
	int m_G;
	int m_B;
	int m_Gradient;	// �����屳��������ϵ��
	float m_Height;  //��ͷ�߶ȣ����Ǳ���,
	int m_fontHeight; //����߶�
	int m_fontWith;   //������
	COLORREF m_color;
	LRESULT OnLayout( WPARAM wParam, LPARAM lParam );
};


