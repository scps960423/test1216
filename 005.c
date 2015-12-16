#include <stdio.h>
#include <stdlib.h>
/* 
	��u�G�� 40318130 �L���p 104/12/2�C 
	Homework5:�`�ٹF�H 

	���D :1.�x�}���פ��T�w 
	 	  2.�����üƲ���	
	 	  3.�p��ϥ��쵲�Ӱ��x�}�ۥ[ 
		  4.�p��ϥ��쵲�Ӱ��x�}�ۭ�-->���ѨM 
		  
		   
		  
	�y�{:1.��JA�x�}�PB�x�}������ 
		 2.�üƲ��ͨ�x�}������ 
		 3.�O�_�}�l 
		 4.�P�_�x�}���׬O�_�X�G�W�h 
		 5.�߰ݬO�_�~��t��     
		 6.�����t�� 
*/ 

//�����x�}�ƭȸ�ƪ����c 
struct matrix_Data
{
	int *matrixA;
	int *matrixB;
	int *matrixC;
};

//A�䵲�A�ΨӼȦsA�x�}�b�O���餤�����
struct linkedListNodeA 
{
    struct matrix_Data data;
    struct linkedListNodeA *nextPtrA;
};
//B�쵲�A�ΨӼȦsB�x�}�b�O���餤�����
struct linkedListNodeB 
{
    struct matrix_Data data;
    struct linkedListNodeB *nextPtrB;
};
//C�쵲�A�ΨӼȦsC�x�}�b�O���餤�����
struct linkedListNodeC 
{
    struct matrix_Data data;
    struct linkedListNodeC *nextPtrC;
};


//�إߤT���쵲����ƫ��A�A�b�D�{�����ɭԥi�H��K�ϥ� 
typedef struct linkedListNodeA LinkedListNodeA;
typedef struct linkedListNodeB LinkedListNodeB;
typedef struct linkedListNodeC LinkedListNodeC;

int main(int argc, char *argv[]) 
{
	
	//���O�ŧi �_�l�I�A�s�W�I�A�ثe��m�����е��T���쵲 
	LinkedListNodeA *startPtrA, *newPtrA, *currentPtrA;
	LinkedListNodeB *startPtrB, *newPtrB, *currentPtrB;
	LinkedListNodeC *startPtrC, *newPtrC, *currentPtrC;
	
	int i,randTextA,randTextB,ansA,ansB;
	int	rowA,columnsA,rowB,columnsB;
	char ch;
	srand((unsigned) time(NULL)); //���Ͷüƺؤl 
	printf("�Y�n�}�l�Ы�Enter\n");
	ch=getch();
	if(ch==13)
	{
		do
		{
			i = 0;
			printf("�п�JA�C:");
			scanf("%d",&rowA);
			printf("�п�JA��:");
			scanf("%d",&columnsA);
			printf("�п�JB�C:");
			scanf("%d",&rowB);
			printf("�п�JB��:");
			scanf("%d",&columnsB);
			
			//�]�w�_�l�l�I����	
		    startPtrA = NULL;   //�e���ѰO 
			// rowA*columnsA>>>���L�x�}���������� 
			while (i < rowA*columnsA) 
			{
			// �Q��malloc�h��M�i�Ϊ��O����Ŷ� 
	        newPtrA = malloc(sizeof(LinkedListNodeA));
			//�ü�	   	
			randTextA=rand()%10;
			//�N���o���üƩ�i���qmalloc���o����}     
			newPtrA->data.matrixA = randTextA;
	        newPtrA->nextPtrA = NULL;
	    
	        //�}�l�N��Ʃ�i�쵲�̭� 
			//startPtrA==NULL�N��ثe�o���쵲�٬O�Ū��S������F�� 
			if (startPtrA == NULL)  
			{
	            startPtrA = newPtrA;
	        }
	        
	        else 
			{
				//�N�ثe��}����}�l��} 
	            currentPtrA = startPtrA;
	            //�u�n��}�����ūh�|�~�򩹤U�@�� 
	            while (currentPtrA != NULL) 
				{
					//�p�G�U�@�Ӹ`�I�O�Ū��h�O�s���@���I�A���X�j�� 
	                if (currentPtrA->nextPtrA == NULL) 
					{
	                    currentPtrA->nextPtrA = newPtrA;
	                    break;
	                }        
	                currentPtrA = currentPtrA->nextPtrA;
	            }
	        }
		   i++;
	    }	
	    //-------���Ϭq�PA�x�}�����ۦP�A���Ѥ譱�аѦҤW��--------------------- 
		   	startPtrB = NULL; 
		   	//i=0 �o�Ӧa��ݭn�S�O�`�N�A�Y�S���Ni���]�����Ϭq�|�L�k���Q����A�]��i�b�W�zA�Ϭq�w���̫� 
		   	i=0;
			while (i < rowB*columnsB) 
			{
	        newPtrB = malloc(sizeof(LinkedListNodeB));      
	   		randTextB=rand()%10;
			newPtrB->data.matrixB = randTextB;
	        newPtrB->nextPtrB = NULL;
			//�N��ƥ[�J�쵲��
	        if (startPtrB == NULL) {
	            startPtrB = newPtrB;
	        }
	        else 
			{
	            currentPtrB = startPtrB;
	             
	            while (currentPtrB != NULL) {
	                if (currentPtrB->nextPtrB == NULL) {
	                    currentPtrB->nextPtrB = newPtrB;
	                    break;
	                }
	                        
	                currentPtrB = currentPtrB->nextPtrB;
	            }
	        }
	     	i++;
	    }
	    //-------���Ϭq�PA�x�}�����ۦP----------------------------------------------------- 
				
			/*
				�ѩ�n�N�Ҧ��s���O����Ŷ�����Ʈ��C�L�X��
				�ҥH�����NcurrentPtrA�PcurrentPtrB�����V�Ĥ@�Ӧ�}�]�N�O�_�l�I
				�Y�S���N currentPtr����_�l��} �h�L�k���QŪ���Ҧ��ƭ�  �]���L���ȷ|�@�����d�b�W����V���̫�@���I 
			*/		
		    currentPtrA = startPtrA;
			currentPtrB = startPtrB; 
		    while (currentPtrA != NULL)
		    {
	    	//���F���L�i�H�ӯx�}���覡�L�X�ҥH���L�CŪ��L����ƴN���U�@�� 
	    	for(i=1;i<=columnsA;i++)
			{
	    		printf("%3d ", currentPtrA->data.matrixA);
	    		//�� currentPtrA���V�U�@�Ӧ�}  
				currentPtrA = currentPtrA->nextPtrA;	
			}
	         printf("\n");
	        
	    	}
		    printf("\n");
		   //----------���Ϭq�P�W�z�ۦP�A���ѽаѦҤW�z-------------------------------------- 
			while (currentPtrB != NULL)
		    {
	    	
	    	for(i=1;i<=columnsB;i++)
			{
	    		printf("%3d ", currentPtrB->data.matrixB);
				currentPtrB = currentPtrB->nextPtrB;	
			}
	         printf("\n");
	        
	    	}
	    	//----------���Ϭq�P�W�z�ۦP�A���ѽаѦҤW�z-------------------------------------- 
			
			/*
				�����}�l���x�}�ۥ[������
				�Y�T�w�����쪺���O��ASCII��13 Enter�A�h�}�l����  
			*/ 
			
		    ch=getch();
			i=0;
			//�o�̱N��}���V�}�l����]�O�]���n�}�l���x�}�ۥ[�������Y�}�l�M��A�PB�x�}�������� 
			currentPtrA = startPtrA;
			currentPtrB = startPtrB;
		    //�@�˭n�NC���_�l�I�]���ū��� 
			startPtrC = NULL;
			if(ch==13)
			{
				//�P�_A�x�}�PB�x�}�����׬O�_�ۦP�A�Y���P�h�|���X���~ 
				if(rowA==rowB && columnsA==columnsB)
			    { 
			    	while (i < rowA*columnsA) 
					{
	 				//�M��i�Ϊ��O����Ŷ�	    
 					newPtrC = malloc(sizeof(LinkedListNodeC));	
					/*
						�o��J��@�Ӱ��D�A�i��O�ګ����쵲������
						�쥻�H���ڥi�H�o�˼g newPtrC->data.matrixC =currentPtrA->data.matrixA+currentPtrB->data.matrixB;
						���O����A���������g�k������
						�ҥH�N�L�̪��ȥt�~��ansA�PansB�o�˴N�i�H���Q���x�}���ۥ[ 
					*/ 
					ansA=currentPtrA->data.matrixA;
					ansB=currentPtrB->data.matrixB;			
					newPtrC->data.matrixC =(ansA+ansB);
			        newPtrC->nextPtrC = NULL;
					
					//�N���ץ[�J�쵲�� 
					if (startPtrC == NULL) 
					{
			            startPtrC = newPtrC;
			        }
			        else 
					{
			            currentPtrC = startPtrC;
			             
			            while (currentPtrC != NULL) 
						{
				            if (currentPtrC->nextPtrC == NULL) 
								{
				                    currentPtrC->nextPtrC = newPtrC;
				                    break;
				                }
			                        
			                currentPtrC = currentPtrC->nextPtrC;
			            }
			        }
				     	i++;
				     	//�� currentPtrA�P currentPtrB���V�U�@����� 
				     	currentPtrA = currentPtrA->nextPtrA;	
				        currentPtrB = currentPtrB->nextPtrB;
		        }	
					printf("\n");
					//�N���צL�X---------------���Ϭq�e�z�ۦP�G�������� 
			   	 	currentPtrC = startPtrC;
					while (currentPtrC != NULL)
				    {
			    	
			    	for(i=1;i<=columnsB;i++)
					{
			    		printf("%3d ", currentPtrC->data.matrixC);
						currentPtrC = currentPtrC->nextPtrC;	
					}
			         printf("\n");
			        //�N���צL�X---------------���Ϭq�e�z�ۦP�G�������� 
			    	}    
			    }
				else
			    {
		    	printf("�x�}���פ��ۦP�G�����ۥ[\n");
		    	}	
			}
			//���̳W�w��J���O
			else
			{
				printf("���~\n");
			}
			printf("�Y�n�~��Ы�Enter,�_�h�Ы����@�����}\n");
			ch=getch();
		}while(ch==13);
	}
	return 0;
}
