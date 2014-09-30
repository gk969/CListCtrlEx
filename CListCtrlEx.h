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

	// 行高
	int m_nRowHeight;
	int InsertColumn(int nCol, LPCTSTR lpszColumnHeading,
		int nFormat = LVCFMT_LEFT, int nWidth = -1, int nSubItem = -1);

	// Gradient - 渐变系数，立体背景用,不用渐变设为0
	void SetHeaderBackColor(int R, int G, int B, int Gradient);

	// 设置表头高度
	void SetHeaderHeight(float Height);
	CPtrList m_ptrListCol;  //保存列颜色
	CPtrList m_ptrListItem; //保存Item颜色表
	CPtrList m_colTextColor; //保存列字体颜色
	CPtrList m_ItemTextColor; //保存单元格字体颜色
	stColor* FindColBackColor(int col); //查找列颜色
	stColor* FindItemBackColor(int col,int row);
	stColor* FindColTextColor(int col); //查找列字体颜色
	stColor* FindItemTextColor(int col,int row);
	void SetColBackColor(int col,COLORREF color);  //设置列颜色
	void SetItemBackColor(int col,int row,COLORREF color); //设置Item颜色
	void SetColTextColor(int col,COLORREF color);   //设置列文本颜色
	void SetItemTextColor(int col,int row,COLORREF color);
	void SetRowHeigt(int nHeight); //设置行高
	void SetHeaderFontHW(int nHeight,int nWith); //设置表头字体大小
	void SetHeaderTextColor(COLORREF color);
	COLORREF m_color;
	BOOL SetTextColor(COLORREF cr);
	void SetFontSize(int nHeight,int nWith);  //设置字体的高和宽

	// 字体高度
	int m_fontHeight;

	// 字体宽度
	int m_fontWith;
};


