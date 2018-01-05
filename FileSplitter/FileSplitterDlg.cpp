// FileSplitterDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "FileSplitter.h"
#include "FileSplitterDlg.h"
// #include "Version.cpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// �A�v���P�[�V�����̃o�[�W�������Ɏg���� CAboutDlg �_�C�A���O

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ����
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
	// ��O : OCX �v���p�e�B �y�[�W�͕K�� FALSE ��Ԃ��܂��B
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CFileSplitterDlg �_�C�A���O




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


// CFileSplitterDlg ���b�Z�[�W �n���h��

BOOL CFileSplitterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// "�o�[�W�������..." ���j���[���V�X�e�� ���j���[�ɒǉ����܂��B

	// IDM_ABOUTBOX �́A�V�X�e�� �R�}���h�͈͓̔��ɂȂ���΂Ȃ�܂���B
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

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
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

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CFileSplitterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N���C�A���g�̎l�p�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R���̕`��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ���[�U�[���ŏ��������E�B���h�E���h���b�O���Ă���Ƃ��ɕ\������J�[�\�����擾���邽�߂ɁA
//  �V�X�e�������̊֐����Ăяo���܂��B
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
	 * ���̓t�@�C���`�F�b�N
	 */
	// ��łȂ���
	if( m_strFilePath.GetLength() == 0 ){
		AfxMessageBox(_T("Error:Please enter the input file."));
		return;
	}
	// �t�@�C�������݂��Ă��邩
	{
		CFileFind finder;
		if( !finder.FindFile(m_strFilePath) ){
			AfxMessageBox(_T("Error:File not exists."));
			return;
		}
	}

	/*
	 * ���̓t�@�C������o�̓t�@�C���������肷��
	 */
	// ���̓t�@�C�����i�o�̓t�@�C���̍쐬�Ŏg�p����j
	CString strInFileName = _T("");		// �t�@�C�����i�g���q�Ȃ��j
	CString strInFileExt = _T("");		// �g���q
	// �o�̓t�@�C�����쐬����t�H���_�i������\�Ȃ��A�t�H���_�쐬�ŕύX�����\������j
	CString strOutFolderPath = _T("");
	// �g���q�����������Ȃ��������̃t���O
	BOOL bFoundExt = TRUE;
	{
		// ���̓t�@�C��������t�H���_���擾�i������\�Ȃ��j
		CString strInFileFolderPath = _T("");
		INT nDirEndPos = m_strFilePath.ReverseFind('\\');
		strInFileFolderPath.Format(_T("%s"), m_strFilePath.Left(nDirEndPos));
		if( strInFileFolderPath.GetLength() == 0 ){
			strInFileFolderPath = _T(".");
		}

		// ���̓t�@�C�����i�p�X�����A�g���q�Ȃ��j�Ɗg���q�i.�Ȃ��j�̕���������
		// .������
		INT nInFileExtPos = m_strFilePath.ReverseFind('.');
		if( 0 <= nInFileExtPos ){
			// ��������
			bFoundExt = TRUE;

			if( nInFileExtPos < nDirEndPos ) nInFileExtPos = m_strFilePath.GetLength()-1;
			strInFileName.Format(_T("%s"), m_strFilePath.Mid(nDirEndPos+1, (nInFileExtPos-nDirEndPos-1)));

			// ���̓t�@�C�����̊g���q
			strInFileExt.Format(_T("%s"), m_strFilePath.Mid(nInFileExtPos-1));
		}else{
			// ������Ȃ�����
			bFoundExt = FALSE;

			strInFileName = m_strFilePath;
			strInFileExt = _T("");
		}
		// �o�̓t�@�C�����쐬����t�H���_�i������\�Ȃ��A�t�H���_�쐬�ŕύX�����\������j
		strOutFolderPath.Format(_T("%s\\%s"), strInFileFolderPath, strInFileName);
	}

	/*
	 * �o�̓t�H���_���쐬����
	 */
	{
		CFileFind cFinder;
		if( cFinder.FindFile(strOutFolderPath) ){
			// ���݂���ꍇ�͕ʖ���T��
			INT nSuffix = 1;
			CString strTmp = strOutFolderPath;
			while( cFinder.FindFile(strOutFolderPath) ){
				// �o�̓t�H���_�̖��O��ύX
				strOutFolderPath.Format(_T("%s_%d"), strTmp, nSuffix++);
			}
		}
		// �t�H���_���쐬����
		INT nRet = MKDIR(strOutFolderPath);
		if( nRet != 0 ){
			AfxMessageBox(_T("Error:MkDir"));
			return;
		}
	}

	/*
	 * ���̓t�@�C���I�[�v��
	 */
//	BOOL bOpenInFile = FALSE;
//	CFile cInFile;
	{
		if( !cInFile.Open(m_strFilePath, CFile::modeRead) ){
			AfxMessageBox(_T("Error:Can't open input file."));
			goto FuncEnd;
		}
		// �I�[�v������
		bOpenInFile = TRUE;
		cInFile.SeekToBegin();
	}

	/*
	 * ���̓t�@�C���̃T�C�Y�ƕ����T�C�Y����A�o�̓t�@�C���̐������肷��
	 */
	ULONGLONG ulInFileSize = 0;
	ULONGLONG ulDivSize = 0;
	INT nOutFileNum = 0;
	{
		// ���̓t�@�C���̃T�C�Y���擾
		ulInFileSize = cInFile.SeekToEnd();
		if( ulInFileSize < 0 ){
			AfxMessageBox(_T("Error:Invaid file size."));
			goto FuncEnd;
		}

		// �����T�C�Y
		ulDivSize = m_nDivSize * 1024 * 1024;

		// �o�̓t�@�C���̐�
		nOutFileNum = (ulInFileSize / ulDivSize) + 1;
	}

	/*
	 * ��x�ɓǂݍ��ރo�b�t�@�̃T�C�Y�����肵�āA�̈���m�ۂ���
	 */
	INT nBuffSize = 0;
	BYTE* bReadBuff = NULL;
	{
		// �P�x�ɓǂݍ��ރT�C�Y������
		nBuffSize = AfxGetApp()->GetProfileInt(INIFILE_SEC_INFILE, INIFILE_KEY_BUFSIZE, INIFILE_DEF_BUFSIZE);
		if( nBuffSize <= 0 ){
			CString strMes = _T("");
			strMes.Format(_T("Error:Invalid value of [%s]"), INIFILE_KEY_BUFSIZE);
			AfxMessageBox(strMes);
			goto FuncEnd;
		}

		// �������m��
		bReadBuff = (BYTE*)malloc(sizeof(BYTE)*nBuffSize);
		if( !bReadBuff ){
			CString strMes = _T("");
			strMes.Format(_T("Error:Can't allocate memory.(size=%d byte)"), nBuffSize);
			AfxMessageBox(strMes);
			goto FuncEnd;
		}
	}

	/*
	 * �t�@�C�����o�͂���
	 */
//	BOOL bOpenOutFile = FALSE;
//	CFile cOutFile;
	{
		// ���̓t�@�C�������ׂēǂݍ��ݏI������t���O
		BOOL bInFileEnd = FALSE;

		// ���̓t�@�C������bReadBuff�ւ̓ǂݍ��݊J�n/�I���ʒu
		ULONGLONG ulStartPos = 0;
		ULONGLONG ulEndPos = 0;

		// �o�̓t�@�C���̃p�X
		CString strOutFilePath = _T("");

		// �o�̓t�@�C���̒ʂ��ԍ�
		INT nOutFileCount = 0;

		// ���s��T�����߂̃o�b�t�@
		BYTE bBrBuff[BR_BUFSIZE];
		memset(bBrBuff, NULL, sizeof(BYTE)*BR_BUFSIZE);

		// �o�C�i����������邩/���Ȃ����̃t���O
		AfxGetApp()->WriteProfileInt(INIFILE_SEC_INFILE, INIFILE_KEY_BINCHECK, 999);
		BOOL bBinCheck = (AfxGetApp()->GetProfileInt(INIFILE_SEC_INFILE, INIFILE_KEY_BINCHECK, INIFILE_DEF_BINCHECK)==1);
		TCHAR caBinCheck[2] = {NULL, NULL};

		while( !bInFileEnd ){
			// �o�̓t�@�C�����J��
			{
				// �o�̓t�@�C���̃p�X������
				strOutFilePath.Format(_T("%s\\%s%s%s_%03d"),
					strOutFolderPath,	// �o�̓t�H���_
					strInFileName,		// ���̓t�@�C����
					bFoundExt ? _T(".") : _T(""),
										// �g���q�̃s���I�h
					bFoundExt ? strInFileExt : _T(""),
										// ���̓t�@�C���g���q
					++nOutFileCount		// �o�̓t�@�C���ԍ�(1-origin)
				);
				if( !cOutFile.Open(strOutFilePath, CFile::modeWrite | CFile::modeCreate ) ){
					CString strMes = _T("");
					strMes.Format(_T("Error:Can't open the output file.(%s)"), strOutFilePath);
					AfxMessageBox(strMes);
					goto FuncEnd;
				}
				bOpenOutFile = TRUE;
			}

			// �o�̓t�@�C���ɏo�͂���A���̓t�@�C���͈̔͂����肷��
				// �J�n�ʒu��ulStartPos
				// �I���ʒuulEndPos�����肷��
				// �I���ʒu�́AulStartPos+ulDivSize �̉��s����(\r\n)��\n�̈ʒu�Ƃ���
			{
				// ��{�� ulStartPos+ulDivSize �̈ʒu�i�ł��҂�������s�ʒu�ɂ͂Ȃ�Ȃ����Ƃ������j
				ulEndPos = ulStartPos + ulDivSize;
				if( ulInFileSize < ulEndPos){
					// ���̓t�@�C���̍s�����������w�����ꍇ�́A���̓t�@�C���̍s���ɂ��āAulEndPos����
					ulEndPos = ulInFileSize;

				}else{

					// ulEndPos�̈ȑO�̉��s��T��
					INT nBrBuffSearchCount = 0;		// BrBuff�g�p�J�E���^�[(�P�񂲂Ƃ�BR_BUFSIZE byte���T���j
					BOOL bFoundBr = FALSE;
					while( !bFoundBr ){
						// �t�@�C��I/O�����炷���߁ABR_BUFSIZE byte���T��
						ULONGLONG ulBufStart = cInFile.Seek(
							ulEndPos - ( BR_BUFSIZE * ( nBrBuffSearchCount + 1 ) ),
							CFile::begin
						);
						cInFile.Read(bBrBuff, sizeof(BYTE)*BR_BUFSIZE);

						// bBrBuff�̌�납��T��
						INT i=0;
						for( i=BR_BUFSIZE-2; (0<=i)&&(!bFoundBr); i-- ){
							if( (bBrBuff[i] == '\r') && (bBrBuff[i+1] == '\n') ){
								// ����
								bFoundBr = TRUE;

								// ulEndPos����
								ulEndPos = ulEndPos - ( BR_BUFSIZE * ( nBrBuffSearchCount + 1 ) )
									+ i+1;
							}

							// ���łɃo�C�i������
							if( bBinCheck ){
								if( bBrBuff[i] <= 8 ){
									AfxMessageBox(_T("Error:The input file may be binary file."));
									goto FuncEnd;
								}
							}
						} // bBrBuff���P���������ĉ��s������T�����[�v

						nBrBuffSearchCount++;
					} // bBrBuff����郋�[�v
				}
			} // ulEndPos�����肷��u���b�N

			// ���̓t�@�C���� ulStartPos ���� ulEndPos ���A�o�̓t�@�C���֏o�͂���
			{
				// �ǂݍ��ރt�@�C���T�C�Y
				ULONGLONG ulReadPlanSize = ulEndPos - ulStartPos + 1;
				// �ǂݍ��񂾃t�@�C���T�C�Y
				ULONGLONG ulReadSize = 0;

				// �J�n�ʒu���V�[�N
				cInFile.Seek(ulStartPos, CFile::begin);
				// ���Ԃɓǂݍ���
				while( ulReadSize+nBuffSize < ulReadPlanSize ){		// �Ō�̂P�s��while�œǂ܂Ȃ�
					// read
					cInFile.Read(bReadBuff, nBuffSize);
					ulReadSize += nBuffSize;

					// write
					cOutFile.Write(bReadBuff, nBuffSize);
				}
				// �Ō�̂P�s�̉��s�̌��\0�ɂȂ��Ăق������߁ANULL�N���A
				memset(bReadBuff, NULL, nBuffSize);
				// �Ō�̂P�s��ǂݏ�������
				// read
				cInFile.Read(bReadBuff, ulEndPos-(ulStartPos+ulReadSize)+1);
				// write
				cOutFile.Write(bReadBuff, ulEndPos-(ulStartPos+ulReadSize)+1);
			}

			// �o�̓t�@�C�����N���[�Y
			cOutFile.Close();
			bOpenOutFile = FALSE;

			// �N���[�W���O
			if( ulInFileSize <= ulEndPos ){
				// �Ō�܂œǂ񂾂̂ŏI��
				bInFileEnd = TRUE;
			}else{
				// ���̊J�n�ʒu������
				ulStartPos = ulEndPos + 1;
			}
		}
	}


	
FuncEnd:
	// ���̓t�@�C�����I�[�v�����̏ꍇ�̓N���[�Y
	if( bOpenInFile ){
		cInFile.Close();
		bOpenInFile = FALSE;
	}
	// �o�̓t�@�C�����I�[�v�����̏ꍇ�̓N���[�Y
	if( bOpenOutFile ){
		cOutFile.Close();
		bOpenOutFile = FALSE;
	}
	// �ǂݍ��ރo�b�t�@���m�ے��̏ꍇ�͉��
	if( bReadBuff ){
		free( bReadBuff );
		bReadBuff = NULL;
	}
	AfxMessageBox(_T("End"));

#if 0	// ����蒼����

#if 0
	// �����T�C�Y
	const UINT nDivSize = ATOI(m_strDivSize)*1024*1024;	// MB�P��
	ULONGLONG lInFileEndPos = cInFile.SeekToEnd();
	ULONGLONG lStartPos = 0;
	ULONGLONG lEndPos = 0;
	ULONGLONG lDivPos = nDivSize;	// �����l=�����T�C�Y
	ULONGLONG lActual = 0;			// ���݂�POS
	BOOL bFileEnd = FALSE;
	INT nOutFileCount = 0;
	//
	// �t�@�C����������
	//
	// �t�@�C���̍Ō�܂ŌJ��Ԃ�
	while( !bFileEnd ){
		//
		// �o�̓t�@�C���I�[�v��
		//
		strOutFilePath.Format(_T("%s\\%s.%s_%03d"),
			strOutFolderPath,	// �o�̓t�H���_
			strInFileName,		// ���̓t�@�C����
			strInFileExt,		// ���̓t�@�C���g���q
			++nOutFileCount		// �o�̓t�@�C���ԍ�(1-origin)
		);
		if( !cOutFile.Open(strOutFilePath, CFile::modeWrite | CFile::modeCreate) ){
			AfxMessageBox(_T("Error OutFile open"));
			goto FuncEnd;
		}
		bOpenOutFile = TRUE;

		// lDivPos�܂ňړ�
		lDivPos = lStartPos + nDivSize;
		if( nInFileSize < lDivPos ){
			lDivPos = nInFileSize;
		}

		memset(buff, NULL, sizeof(BYTE)*nBuffSize);

		// lDivPos-nSearchLen �̈ʒu������։��s������T��
		INT nSearchLen = 0;
		INT nSearchLenDelta = 100;	// 100byte���T��
		INT nLoopCount = 0;
		BOOL bFound = FALSE;
		while( !bFound ){
			nSearchLen += nSearchLenDelta;
			ULONGLONG a = cInFile.Seek(lDivPos-nSearchLen, CFile::begin);
			cInFile.Read(buff, nBuffSize);
			nLoopCount = (nSearchLen==nSearchLenDelta)?(nSearchLen-1):nSearchLenDelta;
			for( i=nLoopCount-1; (0<=i)&&(!bFound); i++ ){
				if( (buff[i] == '\r') && (buff[i+1] == '\n') ){
					// ������
					bFound = TRUE;
					// ��������(\r)(=+1)�܂ŁA����̏o��
					// lEndPos�́A���̎��̕���(=+2)���w��
					lEndPos = cInFile.Seek(lDivPos-nSearchLen+i+2, CFile::begin);
					ASSERT(lStartPos<lEndPos);
				}
			}
		}
		ASSERT(lStartPos<lEndPos);


		// lStartPos�`lEndPos-1�܂�nBuffSize�������ʂ�
		ULONGLONG nReadSize = 0;					// ���ɓǂݍ��񂾃T�C�Y
		ULONGLONG nPlanSize = lEndPos-lStartPos;	// �ǂݍ��ޗ\��̃T�C�Y
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

		// �t�@�C���̍Ōゾ������I��
		if( lInFileEndPos <= lEndPos ){
			bFileEnd = TRUE;
		}else{
			// �Ō�łȂ��̂Ŏ��̏���
			// �J�����g�ʒu+1�����̃X�^�[�g�ʒu
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
	// �o�̓t�@�C���N���[�Y
	if( bOpenOutFile ){
		cOutFile.Close();
		bOpenOutFile = FALSE;
	}
	// ���̓t�@�C���N���[�Y
	if( bOpenInFile ){
		cInFile.Close();
		bOpenInFile = FALSE;
	}
	if( buff ){
		free(buff);
		buff = NULL;
	}
#endif	// ��蒼��
	UpdateData(FALSE);
}
