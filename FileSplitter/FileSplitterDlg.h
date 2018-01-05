// FileSplitterDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once


// CFileSplitterDlg �_�C�A���O
class CFileSplitterDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CFileSplitterDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^

// �_�C�A���O �f�[�^
	enum { IDD = IDD_FILESPLITTER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g


// ����
protected:
	HICON m_hIcon;

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
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
 * ���s������T�����߂̃o�b�t�@�T�C�Y
 */
#define BR_BUFSIZE				100



// ���\�[�X�̍\����
struct VS_VERSIONINFO { 
    WORD  wLength;          // ���̍\���̂̃T�C�Y(2�o�C�g)
    WORD  wValueLength;     // Value�̃T�C�Y(2�o�C�g)
    WORD  wType;            // �o�C�i�����e�L�X�g��(2�o�C�g)
    WCHAR szKey[16];        // "VS_VERSION_INFO\0"��16����(32�o�C�g)
    WORD  Padding1[1];      // 2�o�C�g����č��v40�o�C�g.
    VS_FIXEDFILEINFO Value; // �����Ƀo�[�W�����ԍ�������.
//  WORD  Padding2[];       // �ϒ��̂���C����̍\���̂ł͕\���s��.
//  WORD  Children[];       // ���������܂�Ӗ��̂Ȃ��f�[�^.
};
