// FileSplitter.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CFileSplitterApp:
// このクラスの実装については、FileSplitter.cpp を参照してください。
//

class CFileSplitterApp : public CWinApp
{
public:
	CFileSplitterApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
public:
	virtual int ExitInstance();
};

extern CFileSplitterApp theApp;



/*
 * INIファイル
 */
#define INIFILE_NAME			_T("FileSplitter.ini")
// 入力ファイルに関する初期設定
#define INIFILE_SEC_INFILE		_T("InputFile")
// - １度に読み込む最大バッファサイズ（byte単位）
#define INIFILE_KEY_BUFSIZE		_T("ReadBufByteSize")
#define INIFILE_DEF_BUFSIZE		(1024*1024)
// - バイナリ判定の指示
#define INIFILE_KEY_BINCHECK	_T("BinaryCheck")
#define INIFILE_DEF_BINCHECK	0

