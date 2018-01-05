// FileSplitterDlg.h : ヘッダー ファイル
//

#pragma once


// CFileSplitterDlg ダイアログ
class CFileSplitterDlg : public CDialog
{
// コンストラクション
public:
	CFileSplitterDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_FILESPLITTER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CString m_strFilePath;
	INT m_nDivSize;
	INT m_nDivSize_min;
	INT m_nDivSize_max;
public:
	afx_msg void OnBnClickedBtnFilePath();
	afx_msg void OnBnClickedBtnExec();
};



/*
 * 改行文字を探すためのバッファサイズ
 */
#define BR_BUFSIZE				100



// リソースの構造体
struct VS_VERSIONINFO { 
    WORD  wLength;          // この構造体のサイズ(2バイト)
    WORD  wValueLength;     // Valueのサイズ(2バイト)
    WORD  wType;            // バイナリかテキストか(2バイト)
    WCHAR szKey[16];        // "VS_VERSION_INFO\0"の16文字(32バイト)
    WORD  Padding1[1];      // 2バイト入れて合計40バイト.
    VS_FIXEDFILEINFO Value; // ここにバージョン番号が入る.
//  WORD  Padding2[];       // 可変長のためC言語の構造体では表現不可.
//  WORD  Children[];       // しかもあまり意味のないデータ.
};
