#include<iostream>
#include<string>
#include<list>
#include<sstream>
using namespace std;

class Text{
    protected:
    string content;
    public: 
    Text(string c):content(c){}
    ~Text(){}
    virtual string getInfor(){}
    virtual int getSize(){}
    virtual int getBreakLine(){}


};

class Heading: public Text{
    private:
    int prefixNum;
    
    public:
    Heading(int n,string c):Text(c),prefixNum(n){}
    ~Heading(){}
    string getInfor(){
        return (to_string(prefixNum)+ "." + this->content + "\n");
    }
    
    int getSize(){
        return (this->getInfor()).length();
    }
    int getBreakLine(){
        return line_breaks(this->getInfor());
    }


};

class Paragraph: public Text{
    private:
    //int startspace = 2;
    //string breakline;
    public:
    Paragraph(string c):Text(c){}
    ~Paragraph(){}
    string getInfor(){
        return ("  " + this->content + "\n" + "\n");
    }

    int getSize(){
        return (this->getInfor()).length();
    }
    int getBreakLine(){
        return line_breaks(this->getInfor());
    }

    
};
class Sheet{
    private:
    int width;
    int length;

    public:
    Sheet(int width1,int length1):width(width1),length(length1){}
    ~Sheet(){}
    int getWidth(){
        return width;
    }

};

class Leaflet{
    private:
    int ID;
    list<Text*> elments;
    list<Sheet*> sheets;
    int count = 0;

    public:
    Leaflet(int ID1):ID(ID1){}
    ~Leaflet(){
        for(auto elment: elments){
            if(elment != nullptr){
                delete elment;
            }
        }
    }

    void addSheet(Sheet* s){
        sheets.push_back(s);
    }

    void addText(Text* newText){
        if(newText->getSize()+ count < 1000){
             elments.push_back(newText);
             count += newText->getSize();
        }
       
    }
    void print(Sheet* s){
        for (Text* item:elements){
            int width = s->getWidth();
            int num = item->getInfor();
            string content = item->getInfor();
            for (int i= 1; i<= num\width; i++){
                insert(width*i,content);
            }
            cout << content;
        }
    }
};


int main(){
    Sheet smallsheet(50,50);
    Sheet tinysheet(20,40);
    Text t1 = Heading("Importance of Bees",1);
    Text t2= Paragraph("Bees are important because ...");
    Text t3 = Heading("Threats to Bees",2);
    Text t4 = Paragraph("Significant threats...")；
    Leaflet leaflet(1);
    leaflet.addText(&t1);
    leaflet.addText(&t2);
    leaflet.addText(&t3);
    leaflet.addText(&t4);
    leaflet.addSheet(&smallsheet);
    leaflet.print();

    //add another sheet
    leaflet.addSheet(&tinysheet);
    

}
