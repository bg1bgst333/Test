/* �w�b�_�t�@�C���̃C���N���[�h */
/* �Ǝ��̃w�b�_�t�@�C�� */
#include "file_utility_cstdio.h"	/* �t�@�C�����[�e�B���e�B(C�W�����o��) */

/* �t�@�C���T�C�Y�̎擾. */
size_t get_file_size_w(const wchar_t *path){

  /* �\���̂̏�����. */
  struct _stat sst = {0};	/* _stat�\����sst��{0}�ŏ�����. */

  /* �t�@�C�����̎擾. */
  _wstat(path, &sst);	/* _wstat��path�Ŏ����ꂽ�t�@�C���̏���sst�Ɋi�[. */

  /* �t�@�C���T�C�Y��Ԃ�. */
  return sst.st_size;	/* return��sst.st_size��Ԃ�. */

}