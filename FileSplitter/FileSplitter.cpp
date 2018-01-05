// FileSplitter.cpp : アプリケーションのクラス動作を定義します。
//

#include "stdafx.h"
#include "FileSplitter.h"
#include "FileSplitterDlg.h"
#include "locale.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileSplitterApp

BEGIN_MESSAGE_MAP(CFileSplitterApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CFileSplitterApp コンストラクション

CFileSplitterApp::CFileSplitterApp()
{
	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}


// 唯一の CFileSplitterApp オブジェクトです。

CFileSplitterApp theApp;


// CFileSplitterApp 初期化

BOOL CFileSplitterApp::InitInstance()
{
	// アプリケーション マニフェストが visual スタイルを有効にするために、
	// ComCtl32.dll Version 6 以降の使用を指定する場合は、
	// Windows XP に InitCommonControlsEx() が必要です。さもなければ、ウィンドウ作成はすべて失敗します。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// アプリケーションで使用するすべてのコモン コントロール クラスを含めるには、
	// これを設定します。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// 標準初期化
	// これらの機能を使わずに最終的な実行可能ファイルの
	// サイズを縮小したい場合は、以下から不要な初期化
	// ルーチンを削除してください。
	// 設定が格納されているレジストリ キーを変更します。
	// TODO: 会社名または組織名などの適切な文字列に
	// この文字列を変更してください。
	SetRegistryKey(_T("アプリケーション ウィザードで生成されたローカル アプリケーション"));
	_tsetlocale( LC_ALL, _T("japanese") ); // #include "locale.h"

	// iniファイルのファイル名を設定する
	if( m_pszProfileName ){
		delete ((void*)m_pszProfileName);
		m_pszProfileName = new TCHAR[MAX_PATH];
		if( !m_pszProfileName ) {
			AfxMessageBox(_T("Error:Can't allocate memory!"));
			return FALSE;
		}
//		CString strCurrentDir = _T("");
//		::GetCurrentDirectory(MAX_PATH, strCurrentDir);
//		CString strIniFile = _T("");
//		strIniFile.Format(_T("%s\\%s"), strCurrentDir, INIFILE_NAME);
//		m_pszProfileName = strIniFile.GetBuffer(0);
//		STRCPY_S((TCHAR*)m_pszProfileName, sizeof(TCHAR)*MAX_PATH, strIniFile);

//		strTmp.form

		::GetCurrentDirectory(MAX_PATH, (LPTSTR)m_pszProfileName);	
		STRCAT_S((LPTSTR)m_pszProfileName, MAX_PATH, _T("\\"));
		STRCAT_S((LPTSTR)m_pszProfileName, MAX_PATH, INIFILE_NAME);
	}

	CFileSplitterDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ダイアログが <OK> で消された時のコードを
		//  記述してください。
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ダイアログが <キャンセル> で消された時のコードを
		//  記述してください。
	}

	// ダイアログは閉じられました。アプリケーションのメッセージ ポンプを開始しないで
	//  アプリケーションを終了するために FALSE を返してください。
	return FALSE;
}

int CFileSplitterApp::ExitInstance()
{
	// TODO: ここに特定なコードを追加するか、もしくは基本クラスを呼び出してください。
	if( m_pszProfileName ) {
		delete ((void*)m_pszProfileName);
		m_pszProfileName = NULL;
	}

	return CWinApp::ExitInstance();
}
