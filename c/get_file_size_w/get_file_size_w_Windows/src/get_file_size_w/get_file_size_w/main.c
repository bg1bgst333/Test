/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>		/* �W�����o�� */
#include <sys/types.h>	/* �h���^ */
#include <sys/stat.h>	/* �t�@�C����� */

/* �֐��̃v���g�^�C�v�錾 */
size_t get_file_size_w(const wchar_t *path);	/* �֐�get_file_size_w�̐錾 */

/* main�֐��̒�` */
int main(void){

	/* �t�@�C���T�C�Y�̎擾. */
	size_t file_size = get_file_size_w(L"test.txt");	/* get_file_size_w��"test.txt"�̃t�@�C���T�C�Y���擾. */

	/* file_size���o��. */
	printf("file_size = %d\n", file_size);	/* printf��file_size���擾. */

	/* �v���O�����̏I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}

/* �t�@�C���T�C�Y�̎擾 */
size_t get_file_size_w(const wchar_t *path){

	/* �\���̂̏�����. */
	struct _stat sst = {0};	/* _stat�\����sst��{0}�ŏ�����. */

	/* �t�@�C�����̎擾. */
	_wstat(path, &sst);	/* _wstat��path�Ŏ����ꂽ�t�@�C���̏���sst�Ɋi�[. */

	/* �t�@�C���T�C�Y��Ԃ�. */
	return sst.st_size;	/* return��sst.st_size��Ԃ�. */

}