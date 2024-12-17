#include <stdio.h>     // �W�����o�̓w�b�_�̃C���N���[�h
#include "ppmlib2.h"   // ��ʕ\�������J�b�g���� ppmlib.h
#include "makefname.c" // �A�ԃt�@�C�����̍쐬

// �֐��̃v���g�^�C�v�錾�imakefname.c���̊֐��j
void make_filename(char head[], int keta, int num, char fname[]);

// main�֐��̎n�܂�
int main(void)
{
    int i;                // i:���̓t�@�C���ԍ�
    char fname[256];      // �t�@�C�����p�z��i���o�͌��p�j
    int x, y, col, check; // ����ϐ�

    printf("���摜�̃t���[�� org00001.ppm�`org00200.ppm �Ɣw�i�摜�̍��������o��\n");

    load_color_image(1, "back.ppm");
    copy_color_image(1, 2);

    for (i = 1; i <= 200; i += 20)
    {
        // �A�Ԃ̃t�@�C�����𐶐��iorg00001.ppm�`org00200.ppm�j
        make_filename("input/org", 5, i, fname); // 5:�����̌���

        load_color_image(0, fname);

        // �摜�𔽓]������
        for (y = 0; y < height[0]; y++)
        {
            for (x = 0; x < width[0]; x++)
            {
                check = 0;
                for (col = 0; col < 3; col++)
                {
                    if (image[0][x][y][col] - image[1][x][y][col] >= 30 || image[0][x][y][col] - image[1][x][y][col] <= -30)
                    {
                        check++;
                    }
                }
                if (check > 0)
                {
                    for (col = 0; col < 3; col++)
                    {   
                        //image[2][x][y][col] = image[0][x][y][col];                                                                              //�����x��ς��Ȃ��ꍇ
                        image[2][x][y][col] = (image[1][x][y][col] * (200 - (i + 19)) / 20 + image[0][x][y][col] * (i + 19) / 20) / 10;         //�����x��ς���ꍇ
                    }
                }
            }
        }
    }
    printf("���ʉ摜��human.ppm�Ƃ��ďo�͂��܂���\n");
    save_color_image(2, "human.ppm");
    return 0; // �v���O�����̐���I��
}
