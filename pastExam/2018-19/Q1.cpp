#include<iostream>
#include<string>
#include<cstring>
#include<exception>
using namespace std;

class Category;

class News{
    public:
    int view_counter = 0;
    string const title;
    string const content;
    string const name;
    Category& category;
    //constructor
    News(string t, string c, string n, Category& c):title(t),content(c),name(n),category_ptr(c){}

};

class Source{
    private:
    News* news[1000]; //declare a array with 1000 items, each the type is News*
    public:
    string url;
    //constructor 
    Source(string u):url(u){} 
    //Note: need destructor here since you assign news pointer on the heap
    ~Source(){
        for(int i=0; i <= 1000; i++){
            delete news[i];
        }
    }
    //source have own many news item
    void addNews(string title,string content,string name,Category* c);
    //private attributes can be accessed outside of the calss
    string getNews(string title);
    int getClicksbyCategory(Category* c);

};

class Category{
     public:
    Category(const string& n):name(n){}
    ~Category(){}
    string const name;
    //once created can't delete category instance
    //using smart pointer and static factory method: make constructor private
    static shared_ptr<Category> createInstance(const string& n,const Category* p){
        return make_shared<Category>(n,p);
    }

}；

//this class stores source and category
class DB{
    public:
    Source* source[100];
    Category* category[500];

    //destructor
    ~Category(){
        for(int i = 0; i < 500; i++){
            delete category[i];
        }
        for(int i = 0; i < 100; i++){
            delete source[i];
        }
    }

    void insertNewsItem(string title,string cotent, string author, 
        string categoryName1,string sourceWebpage);
    Source* getSource(string sourceUrl);
    Category* getCategory(string categoryName);
    string getContent(string sourceWebpage, string title);
    string  getHottestCategory();

};

DB db;
 //Question b
    void insertNewsItem(string title,string cotent, string author, 
        string categoryName,string sourceWebpage){
            db.insertNewsItem(title,cotent,author,categoryName,sourceWebpage);  
        }

    void DB::insertNewsItem(string title,string cotent, string author, 
        string categoryName,string sourceWebpage){
             //debug here: add getter function in DB class
        Source* source = getSource(sourceUrl);
        Category* category=getCategory(categoryName1);
        source->addNews(title,content,name,category);          
        }


    Source* DB::getSource(string sourceUrl){
        for(i = 0; i <=100; i++){
            //debug here: assert nullptr
            if(!source[i]){
                if(sourceUrl == source[i] -> url){
                    return source[i];
            }
            }
        }
       
        //if this url not exist in the DB then add a new source with this url in DB
        for(i=0; i <= 100; i++){
            if (source[i]==nullptr){
                source[i] = new Source(sourceUrl);
                return source[i];
            }
        }    
        //other situation
        throw runtime_error;
    }

    Category* DB::getCategory(string categoryName){
        for(i = 0; i <=100; i++){
            //debug here: assert nullptr
            if(!category[i]){
                if(categoryName == category[i]->name){
                    return category[i];
            }
            }
        }
       
        //if this url not exist in the DB then add a new source with this url in DB
        for(i=0; i <= 100; i++){
            if (category[i]==nullptr){
                category[i] = new Category(categoryName);
                return category[i];
            }
        }    
        //other situation
        throw runtime_error;
    }

    void Source::addNews(string title,string content,string name,Category* c){
        for (int i=0; i < 1000; i++){
            if (news[i]==nullptr){
                news[i]== new News(title,content,name,c);
                return;
            }
        }
        throw runtime_error;
    }



//Questionc:
//gets the content of a news item (identified by the url of its source and its title) and increases its click count.
string getContent(string sourceWebpage, string title){
    return db.getContent(sourceWebpage,title);
}

string DB::getContent(string sourceWebpage, string title){
    Source* s=this->getSource(sourceWebpage);
    s->getNews(title);
}

string Source::getNews(string title){
    for (int i = 0; i <= 1000; i++){
        if (news[i]->title == title){
            news[i]->view_counter++;
            return news[i]->content;
        }
    }
    throw runtime_error("fail to get news by titlw")
}


//Question d:finds the hottest category, defined as the one with the most clicked news items.

string  getHottestCategory(){
    db.getHottestCategory();
}

string DB::getHottestCategory(){
    int max = 0;
    string hottestName;
    for (int i = 0; i < 500; i++){
        if(!category[i]){
            int clicks = 0;
            for (int j = 0; j <= 100; j++){
                if(!source[j]){
                clicks=clicks+source[j]->getClicksbyCategory(category[i]);
                }
            }
            if(max<clicks){
                hottestName == category[i]->name;
            }
        }
    }
    return hottestName;
}

int Source::getClicksbyCategory(Category* c){
    int count = 0;
    for(int i = 0; i <= 1000; i++){
        if (!news[i] && (news[i]->category).name == c->name){
            count +=news[i]->view_counter;
        }
    }
    return count;
}









//shared_ptr<Category> instance = Category::createInstance("Sports");

/* Here are examples of how the functions should be used (copied from
exam paper). */
/* DO NOT CHANGE ANYTHING BELOW THIS LINE!!! */
void usage1() {
    auto title = "Something Happened";
    auto text = "London is a city where things happen all the time";
    auto author = "A random stranger";
    auto categoryName = "London News";
    auto sourceWebpage = "http://www.blameberg.com";
    insertNewsItem(title, text, author, categoryName, sourceWebpage);
}

void usage2() {
    auto sourceWebpage = "http://www.blameberg.com";
    auto title = "Something Happened";
    string content = getContent(sourceWebpage, title);
}

void usage3() { //
    auto categoryName = getHottestCategory();
}

int main(int argc, char* argv[]) {
    usage1();
    usage2();
    usage3();
    return 0;
}