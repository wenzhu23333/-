package Filemanager;

import java.io.Serializable;
import java.util.Vector;

//���ڴ��̵��ȵ���
public class DiskDispatch implements Serializable {
    private static final long serialVersionUID = 1L;
    //�����ȷ���
    public static int FCFS(Vector input){
        if(!input.isEmpty())
        {
            Object object = input.firstElement();
            input.remove(input.firstElement());
            return (int) object;
        }
        else return -1;
    }
    //���Ѱ��ʱ������
    public static  int SSTF(int TraceNum,Vector input)
    {
        if(!input.isEmpty())
        {
            int max = 9999;
            int index = 0;
            Object object = 0;
            for (int i = 0;i<input.size();i++)
                if(Math.abs((int)input.get(i)-TraceNum)<max)
                {
                    max = Math.abs((int)input.get(i)-TraceNum);
                    index = i;
                    object = input.get(i);
                }
                input.remove(index);
            return (int)object;
        }
        else return -1;
    }
    //���ݵ��� ,1Ϊ���ŵ����ƶ���0Ϊ��С�ŵ����ƶ�
    public static int SCAN(int direction,int TraceNum,Vector input)
    {
        if(!input.isEmpty())
        {
            int max = 9999;

            int index = -1;
            Object object = 0;
            if(direction == 1)
            {
                for(int i = 0;i<input.size();i++)
                {
                    if ((int)input.get(i)>=TraceNum&&Math.abs((int)input.get(i)-TraceNum)<max)
                    {
                        max = Math.abs((int)input.get(i)-TraceNum);
                        object = input.get(i);
                        index = i;
                    }
                }
                if (index == -1)
                {
                    for(int i = 0;i<input.size();i++)
                    {
                        if ((int)input.get(i)<TraceNum&&Math.abs((int)input.get(i)-TraceNum)<max)
                        {
                            max = Math.abs((int)input.get(i)-TraceNum);
                            object = input.get(i);
                            index = i;
                        }
                    }
                }
            }
            else if(direction == 0)
            {
                for(int i = 0;i<input.size();i++)
                {
                    if ((int)input.get(i)<=TraceNum&&Math.abs((int)input.get(i)-TraceNum)<max)
                    {
                        max = Math.abs((int)input.get(i)-TraceNum);
                        object = input.get(i);
                        index = i;
                    }
                }
                if (index == -1)
                {

                    for(int i = 0;i<input.size();i++)
                    {
                        if ((int)input.get(i)>=TraceNum&&Math.abs((int)input.get(i)-TraceNum)<max)
                        {
                            max = Math.abs((int)input.get(i)-TraceNum);
                            object = input.get(i);
                            index = i;
                        }
                    }
                }
            }
            input.remove(index);
            return (int)object;
        }
        else return -1;
    }
//ѭ��ɨ���㷨
    public static int CSCAN(int direction,int TraceNum,Vector input)
    {
        if(!input.isEmpty())
        {
            int max = 9999;
            int min = -1;
            int index = -1;
            Object object = 0;
            if(direction == 1)
            {
                for(int i = 0;i<input.size();i++)
                {
                    if ((int)input.get(i)>=TraceNum&&Math.abs((int)input.get(i)-TraceNum)<max)
                    {
                        max = Math.abs((int)input.get(i)-TraceNum);
                        object = input.get(i);
                        index = i;
                    }
                }
                if (index == -1)
                {
                    for(int i = 0;i<input.size();i++)
                    {
                        if ((int)input.get(i)<TraceNum&&Math.abs((int)input.get(i)-TraceNum)>min)
                        {
                            min = Math.abs((int)input.get(i)-TraceNum);
                            object = input.get(i);
                            index = i;
                        }
                    }
                }
            }
            else if(direction == 0)
            {
                for(int i = 0;i<input.size();i++)
                {
                    if ((int)input.get(i)<=TraceNum&&Math.abs((int)input.get(i)-TraceNum)<max)
                    {
                        max = Math.abs((int)input.get(i)-TraceNum);
                        object = input.get(i);
                        index = i;
                    }
                }
                if (index == -1)
                {

                    for(int i = 0;i<input.size();i++)
                    {
                        if ((int)input.get(i)>=TraceNum&&Math.abs((int)input.get(i)-TraceNum)>min)
                        {
                            min = Math.abs((int)input.get(i)-TraceNum);
                            object = input.get(i);
                            index = i;
                        }
                    }
                }
            }
            input.remove(index);
            return (int)object;
        }
        else return -1;
    }
}

