// FileSplitter.h : PROJECT_NAME �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"		// ���C�� �V���{��


// CFileSplitterApp:
// ���̃N���X�̎����ɂ��ẮAFileSplitter.cpp ���Q�Ƃ��Ă��������B
//

class CFileSplitterApp : public CWinApp
{
public:
	CFileSplitterApp();

// �I�[�o�[���C�h
	public:
	virtual BOOL InitInstance();

// ����

	DECLARE_MESSAGE_MAP()
public:
	virtual int ExitInstance();
};

extern CFileSplitterApp theApp;



/*
 * INI�t�@�C��
 */
#define INIFILE_NAME			_T("FileSplitter.ini")
// ���̓t�@�C���Ɋւ��鏉���ݒ�
#define INIFILE_SEC_INFILE		_T("InputFile")
// - �P�x�ɓǂݍ��ލő�o�b�t�@�T�C�Y�ibyte�P�ʁj
#define INIFILE_KEY_BUFSIZE		_T("ReadBufByteSize")
#define INIFILE_DEF_BUFSIZE		(1024*1024)
// - �o�C�i������̎w��
#define INIFILE_KEY_BINCHECK	_T("BinaryCheck")
#define INIFILE_DEF_BINCHECK	0

