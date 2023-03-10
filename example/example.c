


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

class Iterator<T<V>>
{
    (V)([])(T, a);
}


instance Iterator<CSV<T>>
{
    inline T ([])(CSV self, int index)
    {
        return csv_parse(self, index);
    }

    inline T ([](CSV self, const char * key))
    {
        return csv_parse_str(self, key);
    }

    inline T ([])(CSV self, N slice) implements Num<N>
    {
        return slice(self, );
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

typedef enum
{
    Just;
    Nothing;
}MaybeType;


typedef struct _Maybe<T> implements Delete<T>
{
    MaybeType type;
    T value;
}Maybe;


instance Eq<Maybe<T>>
{
    bool (==)(Maybe<T> m, MaybeID type)
    {
        return m.type == type
    }
}


void fce()
{
    Maybe<int> mb = just(10);

    if(mb == Just)
        printf("it is just %d\n", mb.value);
    
    if(mb == Nothing)
        printf("Nothing");

}   


Maybe<T> 
just(T)
{
    return (Maybe<T>){true, T};
}


Maybe<T>
nothing(void)
{
    return (Maybe<T>){false};
}


instance Delete<Maybe<T*>> implements Detele<T*>
{
    void delele(Maybe<T> self)
    {
        if(self.is_value == true)
            delete(self.value;)
    }
}   

typedef enum
{
    Left
    , Right
}EitherType;

typedef struct Either<a, b>
{
    EitherType type;

    union
    {
        a left;
        b right;
    };
}Either;


Either<a, b>
left(a value)
{
    return (Either<a, b>) {.type = Left, .left = value};
}


Either<a, b>
right(b value)
{
    return (Either<a, b>) {.type = Right, .right = value};
}


instance Eq<Either<a, b>>
{
    bool (==)(Either<a,b> self, EitherType type)
    {
        return self.type == type;
    }
}

class Monad<M<a>> 
{
    M<b> (>>=) (M<a> m, M<b> (*f)(M<a>));
}


implements Monad<Either<a, b>>
{
    
}

void fce()
{
    Either<char *, int> e = right(10);

    if(e == Right)
        printf("I't is right: %d\n", e.right);
    else
        printf("I't is left: %s\n", e.left)
}

#include <tensor> 

using namespace Tensor;

/**
** vlastosti p??idan?? do jazyka C:
** typov?? t????dy
** typov?? prom??nn??
** specifikace po??adavk?? pro typov?? prom??nn??, jak?? typov?? t????dy musej?? m??t implementovan??
** lambda funkce 
** jmenn?? prostory
** p????stupov?? specifik??tor ve struktur??ch
** p??et????en?? oper??tor??, ale pouze v typov?? t????d??
** p??id??n?? nov??ho datov??ho typu auto
** polymorfismus pro funkce, na z??klad?? vstupn??ch/v??tupn??ch hodnot signatury funkce se rozli??uje konkr??tn?? funkce
** tvorba vlastn??ch oper??tor??, tak ??e jsou uvedeny v kulat??ch z??vork??ch == infixov?? notace
**
** do p??eklada??e implementovat typovou t????du delete, kter?? pokud je implementov??na pro danou struktur se automaticky
** zavol?? na ukazatele vr??cen?? jako v??sledek funkce a nejsou vr??ceny jako v??sledek aktu??ln?? funkce, nebo je mo??n?? ji zavolat ru??n??
** je t??eba hl??dat zda na dan?? ukazatel nebyla ji?? n??hodou zavol??na funkce free
*/

int
main(void)
{
    auto add_tensors = [](Tensor<T> t1, Tensor<T> t2) -> Tensor<T> where T: Arithmetic<T>, Num<T> 
    {
        // implementace t??la lambda funkce
    };

    Tensor<double> result = 
        Tensor<double>(2, {2,2}, {{1, 2}, {2, 1}});

    Tensor<double> t = do_something(*@Tensor(2, {1,2}, {{23}})); //vytvo???? se objekt struktury Tensor a vr??t?? se ukazatel na alokovanou pam????, kter?? se ozna????, ??e se m?? zavolat destruktor a p??ed?? se hodnotou do funkce do_something

    // pomoc?? znaku @ se ozna???? objekt na kter?? se m?? p??i opu??t??n?? bloku zavolat destruktor    

    list * l = csv[{0:3}];
    value * v = csv["heslo"];

    return @list 
        >>= @slice
        >>= @[](Tensor<int> t){return process(t);} 
        >>= show 


    return EXIT_SUCCESS;
}






