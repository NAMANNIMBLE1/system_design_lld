#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string.h>

using namespace std;


/**********************************document elements ***************************************** */

class DocumentElement{
    public:
    // uninitialized constructor
       DocumentElement(){}
    // abstact class method 
    virtual string render() = 0;
};


class TextElement:public DocumentElement{
    private:
        string text;
    public:
        TextElement(string text){
            this->text = text;
        }

        string render() override{
            return text;
        }
};


class ImageElement:public DocumentElement{
    private:
        string image_path;
    
    public:
        ImageElement(string imagePath){
            this->image_path = imagePath;
        }

        string render() override{
            return "[Image: " + image_path + " ]";
        }
};

class NewLineElement:public DocumentElement{
    public:
        string render() override{
            return "\n";
        }
};

class TabSpaceElement:public DocumentElement{
    public:
        string render() override{
            return "\t";
        }
};



/*********************************** document class ****************************** */

class Document:public DocumentElement{
    private:
        vector<DocumentElement*> DocumentElements;
    
    public:
        void addElement(DocumentElement* element){  // element can be of type image path or text (string)
            DocumentElements.push_back(element);
        }

        // render the document by concatinating the all elements 
        string render(){
            // logic : loop on all elements an combine them 
            string result;
            for(auto element : DocumentElements){ // using auto as it is a pointer type
                result += element->render();
            }
            return result;
        }
};


/******************************************** db saving classes ********************************** */


class DbInfrence{
    public:
        DbInfrence(){

        }

        virtual void save(string data) = 0;
};


// saving to file

class SaveToFile:public DbInfrence{
    public:
        void save(string data) override{
            ofstream outfile("document.text");

            if(outfile){
                outfile << data;
                outfile.close();
                cout<<"document saved to document.txt"<<endl;
            }else{
                throw runtime_error("Something unusual happened");
            }
        }
};

// saving to the db

class SaveToDB:public DbInfrence{
    public:
        void save(string data) override {
            cout<<"data has been saved to the db"<<endl;
        }
};


/*************************************client interaction*********************** */


class DocumentEditor{
    private:
        Document* document;
        DbInfrence* storage;
        string RenderedDocument;
    
    public:
        DocumentEditor(Document* document , DbInfrence* storage){
            this->document = document;
            this->storage = storage;
        }

        void addText(string text){
            document->addElement(new TextElement(text));
        }

        void addImage(string imagePath){
            document->addElement(new ImageElement(imagePath));
        }

        void addNewLine(){
            document->addElement(new NewLineElement());
        }

        void addTabSpace(){
            document->addElement(new TabSpaceElement());
        }

        string renderElement(){
            RenderedDocument = document->render();
            return RenderedDocument;
        }

        void saveDocument(){
            storage->save(RenderedDocument);
        }
};

int main() {

    // Create a document
    Document document;

    // Choose where to save
    SaveToFile storage;
    SaveToDB storage2;

    // Create the editor
    DocumentEditor editor(&document, &storage2);

    // Add different elements
    editor.addText("Hello, this is my document.");
    editor.addNewLine();

    editor.addText("This is the second line.");
    editor.addNewLine();

    editor.addTabSpace();
    editor.addText("Indented text.");
    editor.addNewLine();

    editor.addImage("photo.jpg");

    // Render the document
    cout << "----- Rendered Document -----" << endl;
    cout << editor.renderElement() << endl;

    // Save the document
    cout << "\n----- Saving Document -----" << endl;
    editor.saveDocument();

    return 0;
}