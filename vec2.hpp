#ifndef VEC2
#define VEC2
class vec2{
    public:
    vec2(int x_in,int y_in){x=x_in;y=y_in;};
    int x;
    int y;
    bool operator==(vec2& other){
        return (other.x==x && other.y==y);
    }
    //returns lexiographic less then
    bool operator<(vec2&other){
        if(x<other.x){
            return true;
	}else{
            if(y<other.y){
                return true;
	    }else{
	        return false;
	    }

        }

    }
    vec2 operator+(vec2 &other){
        return vec2(other.x+x,other.y+y);
    }
};
#endif
