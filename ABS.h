#pragma once

using namespace std;

template <typename T> class ABS
{
    T *array;
    const float scale = 2.0f;
    int cap, size = 0;

    public:
        ABS()
        {
            cap = 1;
            array = new T[cap];
        }

        ABS(int c)
        {
            cap = c;
            array = new T[cap];
        }

        ABS(const ABS &c)
        {
            cap = c.getMaxCapacity();
            size = c.getSize();
            array = c.getData();
        }

        ABS &operator=(const ABS &a)
        {
            if (this != &a)
            {
                cap = a.getMaxCapacity();
                size = a.getSize();
                array = a.getData();
            }

            return *this;
        }

        ~ABS()
        {
            delete[] array;
        }

        unsigned int getSize()
        {
            return size;
        }

        unsigned int getMaxCapacity()
        {
            return cap;
        }

        T* getData()
        {
            return array;
        }

        void push(T data)
        {
            if (size == cap)
            {
                cap *= scale;
                T *temp = new T[cap];

                for (int i = 0; i < size; i++)
                {
                    temp[i] = array[i];
                }

                delete[] array;
                array = temp;
            }

            array[size] = data;
            size++;
        }

        T pop()
        {
            if (size == 0)
            {
                throw runtime_error("Stack is empty!");
            }
            else
            {
                T val = array[size - 1];
                array[size - 1] = T();
                size--;

                if (((float)size / cap) < (1 / scale))
                {
                    cap /= scale;
                    T *temp = new T[cap];

                    for (int i = 0; i < size; i++)
                    {
                        temp[i] = array[i];
                    }

                    delete[] array;
                    array = temp;
                }

                return val;
            }
        }

        T peek()
        {
            if (size == 0)
            {
                throw runtime_error("Stack is empty!");
            }
            else
            {
                return array[size - 1];
            }
        }
};