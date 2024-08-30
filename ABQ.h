#pragma once

using namespace std;

template <typename T> class ABQ
{
    T *array;
    const float scale = 2.0f;
    int cap, size = 0;

    public:
        ABQ()
        {
            cap = 1;
            array = new T[cap];
        }

        ABQ(int c)
        {
            cap = c;
            array = new T[cap];
        }

        ABQ(const ABQ &c)
        {
            cap = c.getMaxCapacity();
            size = c.getSize();
            array = c.getData();
        }

        ABQ &operator=(const ABQ &a)
        {
            if (this != &a)
            {
                cap = a.getMaxCapacity();
                size = a.getSize();
                array = a.getData();
            }

            return *this;
        }

        ~ABQ()
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

        void enqueue(T data)
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

        T dequeue()
        {
            if (size == 0)
            {
                throw runtime_error("Queue is empty!");
            }
            else
            {
                T val = array[0];
                size--;

                for (int i = 0; i < size; i++)
                {
                    array[i] = array[i + 1];
                }

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
                throw runtime_error("Queue is empty!");
            }
            else
            {
                return array[0];
            }
        }
};