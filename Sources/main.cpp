#include <iostream>
#include <Views/Cell/CellView.h>
#include <PageGenerator/PageGenerator.h>
#include <PageManager.h>



using namespace std;


int main(){



    std::vector<UserData*> userDataVec {
            new UserData("1Stalin.su","Дмитрий", "Болдин","https://sun9-70.userapi.com/c205424/v205424565/2840/Q9ExfkJtduQ.jpg",19 ),
            new UserData("2Kek","Дмитрий", "Гуляченков","https://sun9-14.userapi.com/c844321/v844321164/1e3f38/sjVui97PcoU.jpg",9 ),
            new UserData("3Averkiller","Александр", "Аверкиев","https://sun9-6.userapi.com/c857536/v857536032/10e4a0/yPxRO3gAIb0.jpg",69 ),
            new UserData("Sarkiss","Сергей", "Петренко","https://sun9-49.userapi.com/c850732/v850732072/7dac/26Ja2edmJwU.jpg",19 )
    };

    PageGenerator* pageGenerator = new PageGenerator();
    pageGenerator->generateTablePage( userDataVec,Organize::ONE_LINE_HORIZONTAL);
   std::cout<<pageGenerator->page->toString();

    PageData *pageData = new PageData(userDataVec,PageType::TABLE_OF_USERS,Organize::ONE_LINE_VERTICAL);
    PageManager* pageManager = new PageManager(pageData);
    pageManager->generatePages();


    return 0;
}