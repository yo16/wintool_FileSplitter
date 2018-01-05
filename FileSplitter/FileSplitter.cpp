// FileSplitter.cpp : �A�v���P�[�V�����̃N���X������`���܂��B
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


// CFileSplitterApp �R���X�g���N�V����

CFileSplitterApp::CFileSplitterApp()
{
	// TODO: ���̈ʒu�ɍ\�z�p�R�[�h��ǉ����Ă��������B
	// ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
}


// �B��� CFileSplitterApp �I�u�W�F�N�g�ł��B

CFileSplitterApp theApp;


// CFileSplitterApp ������

BOOL CFileSplitterApp::InitInstance()
{
	// �A�v���P�[�V���� �}�j�t�F�X�g�� visual �X�^�C����L���ɂ��邽�߂ɁA
	// ComCtl32.dll Version 6 �ȍ~�̎g�p���w�肷��ꍇ�́A
	// Windows XP �� InitCommonControlsEx() ���K�v�ł��B�����Ȃ���΁A�E�B���h�E�쐬�͂��ׂĎ��s���܂��B
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �A�v���P�[�V�����Ŏg�p���邷�ׂẴR���� �R���g���[�� �N���X���܂߂�ɂ́A
	// �����ݒ肵�܂��B
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// �W��������
	// �����̋@�\���g�킸�ɍŏI�I�Ȏ��s�\�t�@�C����
	// �T�C�Y���k���������ꍇ�́A�ȉ�����s�v�ȏ�����
	// ���[�`�����폜���Ă��������B
	// �ݒ肪�i�[����Ă��郌�W�X�g�� �L�[��ύX���܂��B
	// TODO: ��Ж��܂��͑g�D���Ȃǂ̓K�؂ȕ������
	// ���̕������ύX���Ă��������B
	SetRegistryKey(_T("�A�v���P�[�V���� �E�B�U�[�h�Ő������ꂽ���[�J�� �A�v���P�[�V����"));
	_tsetlocale( LC_ALL, _T("japanese") ); // #include "locale.h"

	// ini�t�@�C���̃t�@�C������ݒ肷��
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
		// TODO: �_�C�A���O�� <OK> �ŏ����ꂽ���̃R�[�h��
		//  �L�q���Ă��������B
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �_�C�A���O�� <�L�����Z��> �ŏ����ꂽ���̃R�[�h��
		//  �L�q���Ă��������B
	}

	// �_�C�A���O�͕����܂����B�A�v���P�[�V�����̃��b�Z�[�W �|���v���J�n���Ȃ���
	//  �A�v���P�[�V�������I�����邽�߂� FALSE ��Ԃ��Ă��������B
	return FALSE;
}

int CFileSplitterApp::ExitInstance()
{
	// TODO: �����ɓ���ȃR�[�h��ǉ����邩�A�������͊�{�N���X���Ăяo���Ă��������B
	if( m_pszProfileName ) {
		delete ((void*)m_pszProfileName);
		m_pszProfileName = NULL;
	}

	return CWinApp::ExitInstance();
}
