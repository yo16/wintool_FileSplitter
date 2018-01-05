// FileSplitterDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "FileSplitter.h"
#include "FileSplitterDlg.h"
// #include "Version.cpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ダイアログ データ
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

//	CVersion ver;
//	ver

	return TRUE;  // return TRUE unless you set the focus to a control
	// 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CFileSplitterDlg ダイアログ




CFileSplitterDlg::CFileSplitterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileSplitterDlg::IDD, pParent)
#if _DEBUG
	, m_strFilePath(_T("HugeFile.txt"))
#else
	, m_strFilePath(_T(""))
#endif
	, m_nDivSize(50)
	, m_nDivSize_min(10)
	, m_nDivSize_max(500)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileSplitterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_FILEPATH, m_strFilePath);
	DDX_Text(pDX, IDC_EDT_SIZE, m_nDivSize);
	DDV_MinMaxInt(pDX, m_nDivSize, m_nDivSize_min, m_nDivSize_max);
}

BEGIN_MESSAGE_MAP(CFileSplitterDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_EXEC, &CFileSplitterDlg::OnBnClickedBtnExec)
	ON_BN_CLICKED(IDC_BTN_FILEPATH, &CFileSplitterDlg::OnBnClickedBtnFilePath)
END_MESSAGE_MAP()


// CFileSplitterDlg メッセージ ハンドラ

BOOL CFileSplitterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CFileSplitterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CFileSplitterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CFileSplitterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFileSplitterDlg::OnBnClickedBtnFilePath()
{
	UpdateData(TRUE);

	TCHAR	tcCurPath[MAX_PATH+1];
	memset( tcCurPath, NULL, sizeof(TCHAR)*(MAX_PATH+1) );
	CString strTmp = _T("");
	GetCurrentDirectory(MAX_PATH, tcCurPath);

	CFileDialog dlgFile(TRUE, _T("*.*"), NULL, OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR);
	dlgFile.m_ofn.lpstrInitialDir = tcCurPath;
	dlgFile.DoModal();
	CString strPath = dlgFile.GetPathName();
	if( strPath.GetLength() > 0 ){
		m_strFilePath = strPath;
	}

	UpdateData(FALSE);
}


void CFileSplitterDlg::OnBnClickedBtnExec()
{
	UpdateData(TRUE);

//	INT nRet = 0;
//	INT i = 0;
	BOOL bOpenInFile = FALSE;
	CFile cInFile;
	BOOL bOpenOutFile = FALSE;
	CFile cOutFile;

	/*
	 * 入力ファイルチェック
	 */
	// 空でないか
	if( m_strFilePath.GetLength() == 0 ){
		AfxMessageBox(_T("Error:Please enter the input file."));
		return;
	}
	// ファイルが存在しているか
	{
		CFileFind finder;
		if( !finder.FindFile(m_strFilePath) ){
			AfxMessageBox(_T("Error:File not exists."));
			return;
		}
	}

	/*
	 * 入力ファイルから出力ファイル等を決定する
	 */
	// 入力ファイル情報（出力ファイルの作成で使用する）
	CString strInFileName = _T("");		// ファイル名（拡張子なし）
	CString strInFileExt = _T("");		// 拡張子
	// 出力ファイルを作成するフォルダ（末尾の\なし、フォルダ作成で変更される可能性あり）
	CString strOutFolderPath = _T("");
	// 拡張子があったかなかったかのフラグ
	BOOL bFoundExt = TRUE;
	{
		// 入力ファイルがあるフォルダを取得（末尾の\なし）
		CString strInFileFolderPath = _T("");
		INT nDirEndPos = m_strFilePath.ReverseFind('\\');
		strInFileFolderPath.Format(_T("%s"), m_strFilePath.Left(nDirEndPos));
		if( strInFileFolderPath.GetLength() == 0 ){
			strInFileFolderPath = _T(".");
		}

		// 入力ファイル名（パス無し、拡張子なし）と拡張子（.なし）の文字列を作る
		// .を検索
		INT nInFileExtPos = m_strFilePath.ReverseFind('.');
		if( 0 <= nInFileExtPos ){
			// 見つかった
			bFoundExt = TRUE;

			if( nInFileExtPos < nDirEndPos ) nInFileExtPos = m_strFilePath.GetLength()-1;
			strInFileName.Format(_T("%s"), m_strFilePath.Mid(nDirEndPos+1, (nInFileExtPos-nDirEndPos-1)));

			// 入力ファイル名の拡張子
			strInFileExt.Format(_T("%s"), m_strFilePath.Mid(nInFileExtPos-1));
		}else{
			// 見つからなかった
			bFoundExt = FALSE;

			strInFileName = m_strFilePath;
			strInFileExt = _T("");
		}
		// 出力ファイルを作成するフォルダ（末尾の\なし、フォルダ作成で変更される可能性あり）
		strOutFolderPath.Format(_T("%s\\%s"), strInFileFolderPath, strInFileName);
	}

	/*
	 * 出力フォルダを作成する
	 */
	{
		CFileFind cFinder;
		if( cFinder.FindFile(strOutFolderPath) ){
			// 存在する場合は別名を探す
			INT nSuffix = 1;
			CString strTmp = strOutFolderPath;
			while( cFinder.FindFile(strOutFolderPath) ){
				// 出力フォルダの名前を変更
				strOutFolderPath.Format(_T("%s_%d"), strTmp, nSuffix++);
			}
		}
		// フォルダを作成する
		INT nRet = MKDIR(strOutFolderPath);
		if( nRet != 0 ){
			AfxMessageBox(_T("Error:MkDir"));
			return;
		}
	}

	/*
	 * 入力ファイルオープン
	 */
//	BOOL bOpenInFile = FALSE;
//	CFile cInFile;
	{
		if( !cInFile.Open(m_strFilePath, CFile::modeRead) ){
			AfxMessageBox(_T("Error:Can't open input file."));
			goto FuncEnd;
		}
		// オープン成功
		bOpenInFile = TRUE;
		cInFile.SeekToBegin();
	}

	/*
	 * 入力ファイルのサイズと分割サイズから、出力ファイルの数を決定する
	 */
	ULONGLONG ulInFileSize = 0;
	ULONGLONG ulDivSize = 0;
	INT nOutFileNum = 0;
	{
		// 入力ファイルのサイズを取得
		ulInFileSize = cInFile.SeekToEnd();
		if( ulInFileSize < 0 ){
			AfxMessageBox(_T("Error:Invaid file size."));
			goto FuncEnd;
		}

		// 分割サイズ
		ulDivSize = m_nDivSize * 1024 * 1024;

		// 出力ファイルの数
		nOutFileNum = (ulInFileSize / ulDivSize) + 1;
	}

	/*
	 * 一度に読み込むバッファのサイズを決定して、領域を確保する
	 */
	INT nBuffSize = 0;
	BYTE* bReadBuff = NULL;
	{
		// １度に読み込むサイズを決定
		nBuffSize = AfxGetApp()->GetProfileInt(INIFILE_SEC_INFILE, INIFILE_KEY_BUFSIZE, INIFILE_DEF_BUFSIZE);
		if( nBuffSize <= 0 ){
			CString strMes = _T("");
			strMes.Format(_T("Error:Invalid value of [%s]"), INIFILE_KEY_BUFSIZE);
			AfxMessageBox(strMes);
			goto FuncEnd;
		}

		// メモリ確保
		bReadBuff = (BYTE*)malloc(sizeof(BYTE)*nBuffSize);
		if( !bReadBuff ){
			CString strMes = _T("");
			strMes.Format(_T("Error:Can't allocate memory.(size=%d byte)"), nBuffSize);
			AfxMessageBox(strMes);
			goto FuncEnd;
		}
	}

	/*
	 * ファイルを出力する
	 */
//	BOOL bOpenOutFile = FALSE;
//	CFile cOutFile;
	{
		// 入力ファイルをすべて読み込み終わったフラグ
		BOOL bInFileEnd = FALSE;

		// 入力ファイルからbReadBuffへの読み込み開始/終了位置
		ULONGLONG ulStartPos = 0;
		ULONGLONG ulEndPos = 0;

		// 出力ファイルのパス
		CString strOutFilePath = _T("");

		// 出力ファイルの通し番号
		INT nOutFileCount = 0;

		// 改行を探すためのバッファ
		BYTE bBrBuff[BR_BUFSIZE];
		memset(bBrBuff, NULL, sizeof(BYTE)*BR_BUFSIZE);

		// バイナリ判定をするか/しないかのフラグ
		AfxGetApp()->WriteProfileInt(INIFILE_SEC_INFILE, INIFILE_KEY_BINCHECK, 999);
		BOOL bBinCheck = (AfxGetApp()->GetProfileInt(INIFILE_SEC_INFILE, INIFILE_KEY_BINCHECK, INIFILE_DEF_BINCHECK)==1);
		TCHAR caBinCheck[2] = {NULL, NULL};

		while( !bInFileEnd ){
			// 出力ファイルを開く
			{
				// 出力ファイルのパスを決定
				strOutFilePath.Format(_T("%s\\%s%s%s_%03d"),
					strOutFolderPath,	// 出力フォルダ
					strInFileName,		// 入力ファイル名
					bFoundExt ? _T(".") : _T(""),
										// 拡張子のピリオド
					bFoundExt ? strInFileExt : _T(""),
										// 入力ファイル拡張子
					++nOutFileCount		// 出力ファイル番号(1-origin)
				);
				if( !cOutFile.Open(strOutFilePath, CFile::modeWrite | CFile::modeCreate ) ){
					CString strMes = _T("");
					strMes.Format(_T("Error:Can't open the output file.(%s)"), strOutFilePath);
					AfxMessageBox(strMes);
					goto FuncEnd;
				}
				bOpenOutFile = TRUE;
			}

			// 出力ファイルに出力する、入力ファイルの範囲を決定する
				// 開始位置はulStartPos
				// 終了位置ulEndPosを決定する
				// 終了位置は、ulStartPos+ulDivSize の改行文字(\r\n)の\nの位置とする
			{
				// 基本は ulStartPos+ulDivSize の位置（でもぴったり改行位置にはならないことが多い）
				ulEndPos = ulStartPos + ulDivSize;
				if( ulInFileSize < ulEndPos){
					// 入力ファイルの行末よりも後ろを指した場合は、入力ファイルの行末にして、ulEndPos決定
					ulEndPos = ulInFileSize;

				}else{

					// ulEndPosの以前の改行を探す
					INT nBrBuffSearchCount = 0;		// BrBuff使用カウンター(１回ごとにBR_BUFSIZE byteずつ探す）
					BOOL bFoundBr = FALSE;
					while( !bFoundBr ){
						// ファイルI/Oを減らすため、BR_BUFSIZE byteずつ探す
						ULONGLONG ulBufStart = cInFile.Seek(
							ulEndPos - ( BR_BUFSIZE * ( nBrBuffSearchCount + 1 ) ),
							CFile::begin
						);
						cInFile.Read(bBrBuff, sizeof(BYTE)*BR_BUFSIZE);

						// bBrBuffの後ろから探す
						INT i=0;
						for( i=BR_BUFSIZE-2; (0<=i)&&(!bFoundBr); i-- ){
							if( (bBrBuff[i] == '\r') && (bBrBuff[i+1] == '\n') ){
								// 発見
								bFoundBr = TRUE;

								// ulEndPos決定
								ulEndPos = ulEndPos - ( BR_BUFSIZE * ( nBrBuffSearchCount + 1 ) )
									+ i+1;
							}

							// ついでにバイナリ判定
							if( bBinCheck ){
								if( bBrBuff[i] <= 8 ){
									AfxMessageBox(_T("Error:The input file may be binary file."));
									goto FuncEnd;
								}
							}
						} // bBrBuffを１文字ずつ見て改行文字を探すループ

						nBrBuffSearchCount++;
					} // bBrBuffを作るループ
				}
			} // ulEndPosを決定するブロック

			// 入力ファイルの ulStartPos から ulEndPos を、出力ファイルへ出力する
			{
				// 読み込むファイルサイズ
				ULONGLONG ulReadPlanSize = ulEndPos - ulStartPos + 1;
				// 読み込んだファイルサイズ
				ULONGLONG ulReadSize = 0;

				// 開始位置をシーク
				cInFile.Seek(ulStartPos, CFile::begin);
				// 順番に読み込む
				while( ulReadSize+nBuffSize < ulReadPlanSize ){		// 最後の１行はwhileで読まない
					// read
					cInFile.Read(bReadBuff, nBuffSize);
					ulReadSize += nBuffSize;

					// write
					cOutFile.Write(bReadBuff, nBuffSize);
				}
				// 最後の１行の改行の後は\0になってほしいため、NULLクリア
				memset(bReadBuff, NULL, nBuffSize);
				// 最後の１行を読み書きする
				// read
				cInFile.Read(bReadBuff, ulEndPos-(ulStartPos+ulReadSize)+1);
				// write
				cOutFile.Write(bReadBuff, ulEndPos-(ulStartPos+ulReadSize)+1);
			}

			// 出力ファイルをクローズ
			cOutFile.Close();
			bOpenOutFile = FALSE;

			// クロージング
			if( ulInFileSize <= ulEndPos ){
				// 最後まで読んだので終了
				bInFileEnd = TRUE;
			}else{
				// 次の開始位置を決定
				ulStartPos = ulEndPos + 1;
			}
		}
	}


	
FuncEnd:
	// 入力ファイルがオープン中の場合はクローズ
	if( bOpenInFile ){
		cInFile.Close();
		bOpenInFile = FALSE;
	}
	// 出力ファイルがオープン中の場合はクローズ
	if( bOpenOutFile ){
		cOutFile.Close();
		bOpenOutFile = FALSE;
	}
	// 読み込むバッファを確保中の場合は解放
	if( bReadBuff ){
		free( bReadBuff );
		bReadBuff = NULL;
	}
	AfxMessageBox(_T("End"));

#if 0	// ★作り直し中

#if 0
	// 分割サイズ
	const UINT nDivSize = ATOI(m_strDivSize)*1024*1024;	// MB単位
	ULONGLONG lInFileEndPos = cInFile.SeekToEnd();
	ULONGLONG lStartPos = 0;
	ULONGLONG lEndPos = 0;
	ULONGLONG lDivPos = nDivSize;	// 初期値=分割サイズ
	ULONGLONG lActual = 0;			// 現在のPOS
	BOOL bFileEnd = FALSE;
	INT nOutFileCount = 0;
	//
	// ファイル分割処理
	//
	// ファイルの最後まで繰り返し
	while( !bFileEnd ){
		//
		// 出力ファイルオープン
		//
		strOutFilePath.Format(_T("%s\\%s.%s_%03d"),
			strOutFolderPath,	// 出力フォルダ
			strInFileName,		// 入力ファイル名
			strInFileExt,		// 入力ファイル拡張子
			++nOutFileCount		// 出力ファイル番号(1-origin)
		);
		if( !cOutFile.Open(strOutFilePath, CFile::modeWrite | CFile::modeCreate) ){
			AfxMessageBox(_T("Error OutFile open"));
			goto FuncEnd;
		}
		bOpenOutFile = TRUE;

		// lDivPosまで移動
		lDivPos = lStartPos + nDivSize;
		if( nInFileSize < lDivPos ){
			lDivPos = nInFileSize;
		}

		memset(buff, NULL, sizeof(BYTE)*nBuffSize);

		// lDivPos-nSearchLen の位置から後ろへ改行文字を探す
		INT nSearchLen = 0;
		INT nSearchLenDelta = 100;	// 100byteずつ探す
		INT nLoopCount = 0;
		BOOL bFound = FALSE;
		while( !bFound ){
			nSearchLen += nSearchLenDelta;
			ULONGLONG a = cInFile.Seek(lDivPos-nSearchLen, CFile::begin);
			cInFile.Read(buff, nBuffSize);
			nLoopCount = (nSearchLen==nSearchLenDelta)?(nSearchLen-1):nSearchLenDelta;
			for( i=nLoopCount-1; (0<=i)&&(!bFound); i++ ){
				if( (buff[i] == '\r') && (buff[i+1] == '\n') ){
					// 見つけた
					bFound = TRUE;
					// 見つけた次(\r)(=+1)まで、今回の出力
					// lEndPosは、その次の文字(=+2)を指す
					lEndPos = cInFile.Seek(lDivPos-nSearchLen+i+2, CFile::begin);
					ASSERT(lStartPos<lEndPos);
				}
			}
		}
		ASSERT(lStartPos<lEndPos);


		// lStartPos～lEndPos-1までnBuffSizeずつ書き写す
		ULONGLONG nReadSize = 0;					// 既に読み込んだサイズ
		ULONGLONG nPlanSize = lEndPos-lStartPos;	// 読み込む予定のサイズ
		cInFile.Seek(lStartPos, CFile::begin);
		while( nReadSize+nBuffSize < nPlanSize ){
			// read
			cInFile.Read(buff, nBuffSize);
			nReadSize += nBuffSize;

			// write
			cOutFile.Write(buff, nBuffSize);
		}
		memset(buff, NULL, nBuffSize);
//		ASSERT(lEndPos-(lStartPos+nReadSize)<=nBuffSize);
		cInFile.Read(buff, lEndPos-(lStartPos+nReadSize));
		cOutFile.Write(buff, lEndPos-(lStartPos+nReadSize));

		cOutFile.Close();
		bOpenOutFile = FALSE;

		// ファイルの最後だったら終了
		if( lInFileEndPos <= lEndPos ){
			bFileEnd = TRUE;
		}else{
			// 最後でないので次の準備
			// カレント位置+1が次のスタート位置
			lStartPos = cInFile.Seek(0, CFile::current);
		}
	}

	if( buff ){
		free(buff);
		buff = NULL;
	}


#else
#endif


FuncEnd:
	// 出力ファイルクローズ
	if( bOpenOutFile ){
		cOutFile.Close();
		bOpenOutFile = FALSE;
	}
	// 入力ファイルクローズ
	if( bOpenInFile ){
		cInFile.Close();
		bOpenInFile = FALSE;
	}
	if( buff ){
		free(buff);
		buff = NULL;
	}
#endif	// 作り直し
	UpdateData(FALSE);
}
