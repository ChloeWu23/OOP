#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define maxNewsPerSource 100
#define maxSource 100
#define MaxCategory 500

class Category{
    private:
    string categoryname;
    public:
    Category(string n):categoryname(n){}
    ~Category(){}
    string getName(){
        return categoryname;
    }

    //debug: once created can not be deleted??

};

class News;

class Source{
    private:
    string url;
    vector<News*> allNews; //another way it to use array to put all the pointers pf news

    public:
    Source(string url1):url(url1){}
    ~Source(){
        for (int i = 0; i < maxNewsPerSource;i++){
            if (allNews[i] != nullptr){
                delete allNews[i];
            }
        }
    }

     vector<News*> getNews(){
        return allNews;
     }

    void addNews(News* item){
        if(allNews.size()< maxNewsPerSource){
             allNews.push_back(item);
             return;
        }
        throw runtime_error("can not add more news");
       
    }


};

class News{
    private:
    string title;
    string content;
    string author;
    int count = 0;
    Source* source;
    Category& category;

    public:
    News(string t, string c, string a, Source* s, Category& ca):title(t),content(c),
    author(a),source(s),category(ca){}
    ~News(){}
    string getcontent(){
        return content;
    }
    string gettitle(){
        return this->title;
    }
    void increaseCount(){
        count++;
    }
    int getCount(){
        return count;
    }
    Category* getCategory(){
        return &category;
    }

};

class DB{
    private:
    vector<Source*> sources;
    vector<Category*> catagories;

    public:
    DB(){}
    ~DB(){
        for(int i = 0; i < maxSource; i++){
            if(sources[i] != nullptr){
                delete sources[i];
            }
        }

        for (int i = 0; i < MaxCategory; i++){
            if(catagories[i]!= nullptr){
                delete catagories[i];
            }
        }
    }

    void addSource(Source* s){
        if(sources.size() <  maxSource){
            sources.push_back(s);
            return;
        }
        throw runtime_error("can not add more sources");
    }

    void addCategory(Category* item){
        if(this->catagories.size()< MaxCategory){
            catagories.push_back(item);
            return;
        }
        throw runtime_error("can not add more category");
    }

    void insertNews(string title, string text, 
    string author, string categoryName, string sourceWebpage){
        Source* s = new Source(sourceWebpage);
        Category* c = new Category(categoryName);
        for (int i = 0; i < maxSource; i++){
            if(sources[i]==s){
                //add news to this source
                sources[i]->addNews(new News(title,text,author,s,*c));
            }
        }
    }

    string getContent(string sourceWebpage, string title){
        for(auto it:sources){
            Source* s = new Source(sourceWebpage);
            if (it == s){
                //find source already, check news
                auto allnews = it->getNews();
                for(auto item:allnews){
                    if(item->gettitle() == title){
                        item->increaseCount();
                        return item->getcontent();
                    }
                }
            }
        }
        throw runtime_error("cant find such news");
    }
    
    string getHottestCategory(){
        int max = 0;
        string maxName;
        for(auto item:catagories){
            int count = 0;
            string name = item->getName();
            for(auto source:sources){
                auto news = source->getNews();
                for (auto j:news){
                    if(j->getCategory()->getName() == item->getName()){
                        count += j->getCount();
                    }
                }
            }
            if (count > max){
                max = count;
                maxName = item->getName();
            }
        }
        return maxName;
    }


};
DB database;
void insertNewsItem(string title, string text, 
    string author, string categoryName, string sourceWebpage){
    database.insertNews(title,text,author,categoryName,sourceWebpage);    

}

string getContent(string sourceWebpage, string title){
    DB database; //this way also works
    database.getContent(sourceWebpage,title);
}
int main(){
    cout << "enter" << endl;
    auto title = "Something Happened";
    auto text = "London is a city where things happen all the time";
    auto author = "A random stranger";
    //auto categoryName = "London News";
    //auto sourceWebpage = "http://www.blameberg.com";
    //insertNewsItem(title, text, author, categoryName, sourceWebpage);
    //string content = getContent(sourceWebpage, title);
    auto categoryName = getHottestCategory();
    cout << categoryName << endl;

}