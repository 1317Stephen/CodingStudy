/*
 * < Cracking The Coding Interview 6/E >
 * Problem #3.6 There is a animal Shelter where only cats and dogs can be accomodated  
 *              and the oldest animals can be adopted. People only can choose cat or dog.
 *           
 *              Impletent this system including enqueue, dequeueAny, dequeueDog, dequeueCat.
 * 
 * Author: YeEun Ko
 * 
 */
#include<iostream>
#include<queue>
#include<string>
#include<list>
#include<typeinfo>
using namespace std;

class AnimalNode
{
    public:
        int order;
        std::string name;
        std::string date;
        AnimalNode(string name)
        {
            this->name=name;
        }
        AnimalNode(string name, string date)
        {
            this->name=name;
            this->date=date;
        }
        void setName(string name)
        {
            // cout<<"name\n";
            this->name=name;
        }
        void setOrder(int order)
        {
            this->order=order;   
        }
        int getOrder()
        {
            return this->order;
        }
        bool isOlderThan(AnimalNode *a)
        {
            return this->order < a->getOrder();
        }
};
class Dog: public AnimalNode{};
class Cat: public AnimalNode{};

class AnimalShelter
{
    private:
        int order;
    public:
        list<AnimalNode> *dogQ, *catQ, *animalQ;
        AnimalShelter()
        {
            this->order=0;
            dogQ = new list<AnimalNode>;
            catQ = new list<AnimalNode>;
            animalQ = new list<AnimalNode>;
        }
        void enqueue(Dog *dog)
        {
            this->order++;
            dog->setOrder(this->order);
            this->dogQ->push_back(*dog);
            //cout<<"sameDog: "<<(bool)(typeid(*dog)==typeid(Dog))<<"\n";
        }
        void enqueue(Cat *cat)
        {
            this->order++;
            cat->setOrder(this->order);
            this->catQ->push_back(*cat);
            //cout<<"sameDog: "<<(bool)(typeid(*dog)==typeid(Dog))<<"\n";
        }
        AnimalNode dequeueAny()
        {
            if(dogQ->size()==0)
            {
                return (catQ->front());
            }
            else if(catQ->size()==0)
            {
                return (dogQ->front());
            }
            AnimalNode dog = dogQ->front();
            AnimalNode cat = catQ->front();
            if(dog.isOlderThan(&cat))
            {
                // cout<<"dog is older: "<<dog.getOrder()<<"\n";
                return dequeueDog();
            }
            else
            {
                // cout<<"cat is older: "<<cat.getOrder()<< dog.getOrder()<<"\n";
                return dequeueCat();
            }
        }
        AnimalNode dequeueDog()
        {
            // if(dogQ->size()==0)
            // {
            //     return 0;
            // }
            AnimalNode dog=dogQ->front();
            dogQ->pop_front();
            return dog;
        }
        AnimalNode dequeueCat()
        {
            // if(catQ->size()==0)
            // {
            //     return 0;
            // }
            AnimalNode cat=catQ->front();
            catQ->pop_front();
            return cat;
        }        

};

int main()
{
    AnimalShelter *shelter = new AnimalShelter();
    Dog*dog1; Dog*dog2 ;
    Cat*cat1; Cat*cat2;

    dog1=(Dog*)malloc(sizeof(Dog));
    dog1->setName("dog1");
    // cout<<"dog1\n";
    dog2=(Dog*)malloc(sizeof(Dog));
    // cout<<"dog2\n";
    dog2->setName("dog2");
    
    
    // cout<<"setDog\n";

    cat1=(Cat*)malloc(sizeof(Cat));
    // cout<<"malloc cat\n";
    cat1->setName("cat1");
    cat2=(Cat*)malloc(sizeof(Cat));
    cat2->setName("cat2");

    // cout<<"set\n";

    shelter->enqueue(dog1);
    shelter->enqueue(dog2);
    shelter->enqueue(cat1);
    shelter->enqueue(cat2);

    // cout<<"enqueue\n";

    AnimalNode a = shelter->dequeueCat();
    cout<<a.name;

    
    //cout<<(string)(typeid(*dog))<<"\n";
    return 0;
}
