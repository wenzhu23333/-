function last_answer=a_find_answer(data,xingyu,r_md,h_md)
n=size(data,1);
m=size(data,2);
answer=zeros(n,m);     %�������е����۵÷�Ԥ�����ڴ�ӿ촦���ٶ�
last_answer=zeros(n,3);   %���ս����[���۵÷֣��ɱ��������]
for i=1:n
    for j=1:m
        if(data(i,j)>=38115)
            answer(i,j)=0;
        else
            temp_cost=c_cost(data(i,j));
            cost=temp_cost+r_md(i,1)-h_md(i,1);
            answer(i,j)=1/cost+0.0036*xingyu(j,1)+1/85;
        end
    end
end
index=ones(n,1);
max=zeros(n,1);
for i=1:n
    for j=1:m
        if(answer(i,j)>max(i,1))
            max(i,1)=answer(i,j);
            index(i,1)=j;
        end
    end
end

%[y,u]=max(temp_answer);    %yΪÿһ�е����ֵ��uΪÿһ�����ֵ��������
for i=1:n
    last_answer(i,1)=max(i,1);
    last_answer(i,2)=c_cost(data(i,index(i,1)));
    last_answer(i,3)=xingyu(index(i,1),1);
end





