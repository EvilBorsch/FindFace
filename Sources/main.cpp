#include <iostream>
#include <fstream>
#include "Views/PersonView/PersonView.h"
#include "Views/Cell/CellView.h"
#include "Views/TableView/TableView.h"
#include "PageGenerator/PageGenerator.h"



using namespace std;


int main(){



    std::vector<UserData*> userDataVec {
            new UserData("1Stalin.su","Дмитрий", "Болдин","https://sun9-60.userapi.com/c855624/v855624982/135c19/xi-ReZmdN70.jpg",19 ),
            new UserData("2Kek","Дмитрий", "Гуляченков","https://sun9-14.userapi.com/c844321/v844321164/1e3f38/sjVui97PcoU.jpg",9 ),
            new UserData("3Averkiller","Александр", "Аверкиев","https://upload.wikimedia.org/wikipedia/commons/thumb/e/e0/Anonymous.svg/866px-Anonymous.svg.png",69 ),

            new UserData("4Stalin.su","Дмитрий2", "Болдин","https://sun9-60.userapi.com/c855624/v855624982/135c19/xi-ReZmdN70.jpg",19 ),
            new UserData("5Kek","Дмитрий2", "Гуляченков","https://sun9-14.userapi.com/c844321/v844321164/1e3f38/sjVui97PcoU.jpg",9 ),
            new UserData("6Averkiller","Александр2", "Аверкиев","https://upload.wikimedia.org/wikipedia/commons/thumb/e/e0/Anonymous.svg/866px-Anonymous.svg.png",69 ),

            new UserData("7Stalin.su","Дмитрий3", "Болдин","https://sun9-60.userapi.com/c855624/v855624982/135c19/xi-ReZmdN70.jpg",19 ),
            new UserData("8Kek","Дмитрий3", "Гуляченков","https://sun9-14.userapi.com/c844321/v844321164/1e3f38/sjVui97PcoU.jpg",9 ),



    };

    PageGenerator* pageGenerator = new PageGenerator();
    pageGenerator->generatePage( *new PageData(userDataVec, PageType::TABLE_OF_USERS, Organize::ONE_LINE_VERTICAL));
    std::cout<<pageGenerator->page->toString();



    return 0;
}