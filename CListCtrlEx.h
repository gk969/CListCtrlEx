#pragma once
#include "CHeaderCtrlEx.h"
// CListCtrlEx


struct stColor
{
	int nRow;
	int nCol;
	COLORREF rgb;
};

class CListCtrlEx : public CListCtrl
{
	DECLARE_DYNAMIC(CListCtrlEx)

protected:
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();

public:
	CHeaderCtrlEx m_Header;
	CListCtrlEx();
	virtual ~CListCtrlEx();

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);

	// �и�
	int m_nRowHeight;
	int InsertColumn(int nCol, LPCTSTR lpszColumnHeading,
		int nFormat = LVCFMT_LEFT, int nWidth = -1, int nSubItem = -1);

	// Gradient - ����ϵ�������屳����,���ý�����Ϊ0
	void SetHeaderBackColor(int R, int G, int B, int Gradient);

	// ���ñ�ͷ�߶�
	void SetHeaderHeight(float Height);
	CPtrList m_ptrListCol;  //��������ɫ
	CPtrList m_ptrListItem; //����Item��ɫ��
	CPtrList m_colTextColor; //������������ɫ
	CPtrList m_ItemTextColor; //���浥Ԫ��������ɫ
	stColor* FindColBackColor(int col); //��������ɫ
	stColor* FindItemBackColor(int col,int row);
	stColor* FindColTextColor(int col); //������������ɫ
	stColor* FindItemTextColor(int col,int row);
	void SetColBackColor(int col,COLORREF color);  //��������ɫ
	void SetItemBackColor(int col,int row,COLORREF color); //����Item��ɫ
	void SetColTextColor(int col,COLORREF color);   //�������ı���ɫ
	void SetItemTextColor(int col,int row,COLORREF color);
	void SetRowHeigt(int nHeight); //�����и�
	void SetHeaderFontHW(int nHeight,int nWith); //���ñ�ͷ�����С
	void SetHeaderTextColor(COLORREF color);
	COLORREF m_color;
	BOOL SetTextColor(COLORREF cr);
	void SetFontSize(int nHeight,int nWith);  //��������ĸߺͿ�

	// ����߶�
	int m_fontHeight;

	// ������
	int m_fontWith;
};


