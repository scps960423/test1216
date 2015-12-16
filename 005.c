#include <stdio.h>
#include <stdlib.h>
/* 
	資工二甲 40318130 林韻如 104/12/2。 
	Homework5:節省達人 

	問題 :1.矩陣維度不固定 
	 	  2.元素亂數產生	
	 	  3.如何使用鏈結來做矩陣相加 
		  4.如何使用鏈結來做矩陣相乘-->未解決 
		  
		   
		  
	流程:1.輸入A矩陣與B矩陣的維度 
		 2.亂數產生兩矩陣的元素 
		 3.是否開始 
		 4.判斷矩陣維度是否合乎規則 
		 5.詢問是否繼續系統     
		 6.結束系統 
*/ 

//紀錄矩陣數值資料的結構 
struct matrix_Data
{
	int *matrixA;
	int *matrixB;
	int *matrixC;
};

//A鍵結，用來暫存A矩陣在記憶體中的資料
struct linkedListNodeA 
{
    struct matrix_Data data;
    struct linkedListNodeA *nextPtrA;
};
//B鏈結，用來暫存B矩陣在記憶體中的資料
struct linkedListNodeB 
{
    struct matrix_Data data;
    struct linkedListNodeB *nextPtrB;
};
//C鏈結，用來暫存C矩陣在記憶體中的資料
struct linkedListNodeC 
{
    struct matrix_Data data;
    struct linkedListNodeC *nextPtrC;
};


//建立三個鏈結的資料型態，在主程式的時候可以方便使用 
typedef struct linkedListNodeA LinkedListNodeA;
typedef struct linkedListNodeB LinkedListNodeB;
typedef struct linkedListNodeC LinkedListNodeC;

int main(int argc, char *argv[]) 
{
	
	//分別宣告 起始點，新增點，目前位置的指標給三個鏈結 
	LinkedListNodeA *startPtrA, *newPtrA, *currentPtrA;
	LinkedListNodeB *startPtrB, *newPtrB, *currentPtrB;
	LinkedListNodeC *startPtrC, *newPtrC, *currentPtrC;
	
	int i,randTextA,randTextB,ansA,ansB;
	int	rowA,columnsA,rowB,columnsB;
	char ch;
	srand((unsigned) time(NULL)); //產生亂數種子 
	printf("若要開始請按Enter\n");
	ch=getch();
	if(ch==13)
	{
		do
		{
			i = 0;
			printf("請輸入A列:");
			scanf("%d",&rowA);
			printf("請輸入A行:");
			scanf("%d",&columnsA);
			printf("請輸入B列:");
			scanf("%d",&rowB);
			printf("請輸入B行:");
			scanf("%d",&columnsB);
			
			//設定起始始點為空	
		    startPtrA = NULL;   //容易忘記 
			// rowA*columnsA>>>為他矩陣內的元素數 
			while (i < rowA*columnsA) 
			{
			// 利用malloc去找尋可用的記憶體空間 
	        newPtrA = malloc(sizeof(LinkedListNodeA));
			//亂數	   	
			randTextA=rand()%10;
			//將取得的亂數放進剛剛從malloc取得的位址     
			newPtrA->data.matrixA = randTextA;
	        newPtrA->nextPtrA = NULL;
	    
	        //開始將資料放進鏈結裡面 
			//startPtrA==NULL代表目前這個鏈結還是空的沒有任何東西 
			if (startPtrA == NULL)  
			{
	            startPtrA = newPtrA;
	        }
	        
	        else 
			{
				//將目前位址指到開始位址 
	            currentPtrA = startPtrA;
	            //只要位址不為空則會繼續往下一個 
	            while (currentPtrA != NULL) 
				{
					//如果下一個節點是空的則是新的一個點，跳出迴圈 
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
	    //-------此區段與A矩陣部分相同，註解方面請參考上方--------------------- 
		   	startPtrB = NULL; 
		   	//i=0 這個地方需要特別注意，若沒有將i重設那此區段會無法順利執行，因為i在上述A區段已為最後 
		   	i=0;
			while (i < rowB*columnsB) 
			{
	        newPtrB = malloc(sizeof(LinkedListNodeB));      
	   		randTextB=rand()%10;
			newPtrB->data.matrixB = randTextB;
	        newPtrB->nextPtrB = NULL;
			//將資料加入鏈結裡
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
	    //-------此區段與A矩陣部分相同----------------------------------------------------- 
				
			/*
				由於要將所有存放到記憶體空間的資料拿列印出來
				所以必須將currentPtrA與currentPtrB都指向第一個位址也就是起始點
				若沒有將 currentPtr指到起始位址 則無法順利讀取所有數值  因為他的值會一直停留在上方指向的最後一個點 
			*/		
		    currentPtrA = startPtrA;
			currentPtrB = startPtrB; 
		    while (currentPtrA != NULL)
		    {
	    	//為了讓他可以照矩陣的方式印出所以讓他每讀到他的行數就換下一行 
	    	for(i=1;i<=columnsA;i++)
			{
	    		printf("%3d ", currentPtrA->data.matrixA);
	    		//讓 currentPtrA指向下一個位址  
				currentPtrA = currentPtrA->nextPtrA;	
			}
	         printf("\n");
	        
	    	}
		    printf("\n");
		   //----------此區段與上述相同，註解請參考上述-------------------------------------- 
			while (currentPtrB != NULL)
		    {
	    	
	    	for(i=1;i<=columnsB;i++)
			{
	    		printf("%3d ", currentPtrB->data.matrixB);
				currentPtrB = currentPtrB->nextPtrB;	
			}
	         printf("\n");
	        
	    	}
	    	//----------此區段與上述相同，註解請參考上述-------------------------------------- 
			
			/*
				此為開始做矩陣相加的部分
				若確定接收到的指令為ASCII的13 Enter，則開始執行  
			*/ 
			
		    ch=getch();
			i=0;
			//這裡將位址指向開始的原因是因為要開始做矩陣相加必須重頭開始尋找A與B矩陣內的元素 
			currentPtrA = startPtrA;
			currentPtrB = startPtrB;
		    //一樣要將C的起始點設為空指標 
			startPtrC = NULL;
			if(ch==13)
			{
				//判斷A矩陣與B矩陣的維度是否相同，若不同則會跳出錯誤 
				if(rowA==rowB && columnsA==columnsB)
			    { 
			    	while (i < rowA*columnsA) 
					{
	 				//尋找可用的記憶體空間	    
 					newPtrC = malloc(sizeof(LinkedListNodeC));	
					/*
						這邊遇到一個問題，可能是我指標鏈結不夠熟
						原本以為我可以這樣寫 newPtrC->data.matrixC =currentPtrA->data.matrixA+currentPtrB->data.matrixB;
						但是不行，任何類似寫法都不行
						所以將他們的值另外給ansA與ansB這樣就可以順利做矩陣的相加 
					*/ 
					ansA=currentPtrA->data.matrixA;
					ansB=currentPtrB->data.matrixB;			
					newPtrC->data.matrixC =(ansA+ansB);
			        newPtrC->nextPtrC = NULL;
					
					//將答案加入鏈結裡 
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
				     	//讓 currentPtrA與 currentPtrB指向下一筆資料 
				     	currentPtrA = currentPtrA->nextPtrA;	
				        currentPtrB = currentPtrB->nextPtrB;
		        }	
					printf("\n");
					//將答案印出---------------此區段前述相同故不做解釋 
			   	 	currentPtrC = startPtrC;
					while (currentPtrC != NULL)
				    {
			    	
			    	for(i=1;i<=columnsB;i++)
					{
			    		printf("%3d ", currentPtrC->data.matrixC);
						currentPtrC = currentPtrC->nextPtrC;	
					}
			         printf("\n");
			        //將答案印出---------------此區段前述相同故不做解釋 
			    	}    
			    }
				else
			    {
		    	printf("矩陣維度不相同故不做相加\n");
		    	}	
			}
			//未依規定輸入指令
			else
			{
				printf("錯誤\n");
			}
			printf("若要繼續請按Enter,否則請按任一鍵離開\n");
			ch=getch();
		}while(ch==13);
	}
	return 0;
}
