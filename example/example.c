


namespace Tensor 
{
    typedef struct Tensor <T> implements Num<T> Aritmetic<T>
    {
        private uint32_t ndim;
        private uint32_t shape[];
        private T data[];
    }Tensor


    class Aritmetic<T>
    {
        T (+)(T x, T y);
        T (-)(T x, T y);
        T (*)(T x, T y);
        T negate(T x);
        T abs(T x);
        T signum(T x);
        T fromInteger(int x);
    }

    instance Aritmetic<double>
    {
        double 
        (+)(double x, double y)     // operator overloading
        {
            return x + y;
        }

        double 
        (-)(double x, double y) 
        {
            return x - y;
        }

        double 
        (*)(double x, double y) 
        {
            return x * y;
        };
        
        double 
        negate(double x) 
        {
            return -x;
        }

        double 
        abs(double x)
        {
            return  x < 0 ? -x : x;
        }

        double 
        signum(double x)
        {
            x < 0 ? -1 : (x == 0 ? 0 : 1);
        }

        double 
        fromInteger(int x)
        {
            return (double) x;
        }
    } 
}

class Delete<T>
{
    void delete(T *);
}


instance Delete<Tensor<T>*>
{
    void 
    delete(Tensor<T> * self)
    {
        if(self != NULL)
        {
            delete(self->shape);
            delete(self->data);
            free(self);
        }
    }
} 


class Memory.Delete<Tensor.Tensor<T>>
{

}


typedef struct _Maybe<T> implements Delete<T>
{
    bool is_value;
    T value;
}Maybe;


Maybe<T> 
just(T)
{
    return Maybe{true, T};
}

Maybe<T>
nothing(void)
{
    return Maybe{false};
}


instance Delete<Maybe<T>> implements Detele<T>
{
    

    void delele(Maybe<T> self)
    {
        if(self.is_value == true)
            delete(self.value;)
    }
}   


#include <tensor> 

using namespace Tensor;

/**
** vlastosti přidané do jazyka C:
** typové třídy
** typové proměnné
** specifikace požadavků pro typové proměnné, jaké typové třídy musejí mít implementované
** lambda funkce 
** jmenné prostory
** přístupové specifikátor ve strukturách
** přetížení operátorů, ale pouze v typové třídě
** přidání nového datového typu auto
**
** do překladače implementovat typovou třídu delete, která pokud je implementována pro danou struktur se automaticky
** zavolá na ukazatele vrácené jako výsledek funkce a nejsou vráceny jako výsledek aktuální funkce, nebo je možné ji zavolat ručně
** je třeba hlídat zda na daný ukazatel nebyla již náhodou zavolána funkce free
*/

int
main(void)
{
    auto add_tensors = [](Tensor<T> t1, Tensor<T> t2) -> Tensor<T> where T: Arithmetic<T>, Num<T> 
    {
        // implementace těla lambda funkce
    };

    Tensor<double> result = 
        Tensor<double>(2, {2,2}, {{1, 2}, {2, 1}});

    Tensor<double> t = do_something(*@Tensor(2, {1,2}, {{23}})); //vytvoří se objekt struktury Tensor a vrátí se ukazatel na alokovanou paměť, která se označí, že se má zavolat destruktor a předá se hodnotou do funkce do_something

    // pomocí znaku @ se označí objekt na který se má při opuštění bloku zavolat destruktor    

    

    return EXIT_SUCCESS;
}






