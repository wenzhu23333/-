package text_disposal;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Map;
import java.util.TreeMap;
import java.util.jar.Attributes.Name;

import javax.accessibility.AccessibleAction;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
public class textprocess extends JFrame implements ActionListener {
	public static String msg=null;
	private JPanel pn=new JPanel();
	private JPanel pc=new JPanel();
	private JButton btopen=new JButton("���ļ�");
	private JButton btrole=new JButton("��������");
	private JButton btnum=new JButton("����");
	private JButton btdensity=new JButton("�ܶ�");
	private JButton btanaly=new JButton("ѡ������");
	private JButton btshow=new JButton("���ܶ�");
	private JTextArea screen=new JTextArea(20, 55);
	public textprocess()
	{
		screen.setWrapStyleWord(true);//������в����ֹ���
		screen.setLineWrap(true); //���jtextarea�Զ����еĹ���
		this.setSize(800,700);
		pc.add(new JScrollPane(screen));//��jtextarea��ӹ�����
		int windowWidth = this.getWidth(); //��ô��ڿ�
		int windowHeight = this.getHeight(); //��ô��ڸ�
		Toolkit kit = Toolkit.getDefaultToolkit(); //���幤�߰�
		Dimension screenSize = kit.getScreenSize(); //��ȡ��Ļ�ĳߴ�
		int screenWidth = screenSize.width; //��ȡ��Ļ�Ŀ�
		int screenHeight = screenSize.height; //��ȡ��Ļ�ĸ�
		this.setLocation(screenWidth/2-windowWidth/2, screenHeight/2-windowHeight/2);
		this.setVisible(true);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		pn.setLayout(new GridLayout(1, 6, 40, 40));
		screen.setFont(new Font("����", Font.PLAIN, 25));
		this.setLayout(new BorderLayout(10,10));
		pn.add(btopen);
		btopen.addActionListener(this);
		pn.add(btrole);
		btrole.addActionListener(this);
		pn.add(btnum);
		btnum.addActionListener(this);
		pn.add(btdensity);
		btdensity.addActionListener(this);
		pn.add(btanaly);
		btanaly.addActionListener(this);
		pn.add(btshow);
		btshow.addActionListener(this);
		this.add(pn,BorderLayout.NORTH);
		this.add(pc,BorderLayout.CENTER);
	}
			

public void actionPerformed(ActionEvent e)
{
	if(e.getSource()==btopen)
	{
		File file=null;
		JFileChooser chooser=new JFileChooser();
		FileNameExtensionFilter filter = new FileNameExtensionFilter(
		        ".txt", "txt");
	    chooser.setFileFilter(filter);
	    chooser.setDialogTitle("��ѡ���ļ���");
	    int result=chooser.showOpenDialog(this);
	    if(result==JFileChooser.APPROVE_OPTION)
	       file=chooser.getSelectedFile();
	    FileInputStream fis = null;
		try {
			fis = new FileInputStream(file);
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		byte[] data=new byte[(int)file.length()];
		try {
			fis.read(data);
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		textprocess.msg=new String(data);
		try {
			fis.close();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		screen.append("���ڼ���С˵����\n");
		screen.append("С˵������ϣ���С˵Ϊ��"+file.getName().substring(0, file.getName().indexOf("."))+"��\n");
		screen.append("��"+msg.length()+"��\n");
	}
	else if(e.getSource()==btrole)
	{
		if(textprocess.msg==null)
			{
			new error();
			}
		else 
		{
			new input();
		}	
	}
	else if(e.getSource()==btnum)
	{
		if(textprocess.msg==null)
		{
			new error();
		}
		else if(input.tap==false)
		{
			new error2();
		}
		else 
		{
			TreeMap<String, Integer> tx = new TreeMap<String, Integer>();
			for(int i=0;i<10;i++)
				tx.put(input.name[i], StringStat.number[i]);
			List<Map.Entry<String, Integer>> entryArrayList = new ArrayList<>(tx.entrySet());
	        Collections.sort(entryArrayList, Comparator.comparing(Map.Entry::getValue));
	        screen.append("-------------------------------------------------\n");
	        for (Map.Entry<String, Integer> entry : entryArrayList) {
	            screen.append(entry.getKey() + "���ִ���Ϊ��" + entry.getValue()+"\n");
			
		}
		}
	}
	else if(e.getSource()==btdensity)
	{
		if(textprocess.msg==null)
		{
			new error();
		}
		else if(input.tap==false)
		{
			new error2();
		}
		else
		{
			new showdensity();
		}
	}
	else if(e.getSource()==btanaly)
	{
		if(textprocess.msg==null)
		{
			new error();
		}
		else if(input.tap==false)
		{
			new error2();
		}
		else 
		{
			new analy();
	    }
		}
	
else if(e.getSource()==btshow)
{
	if(textprocess.msg==null)
	{
		new error();
	}
	else if(input.tap==false)
	{
		new error2();
	}
	else 
	{
		TreeMap<String, Integer> tm = new TreeMap<String, Integer>();
		tm=StringStat.cal_analy();
		List<Map.Entry<String, Integer>> entryArrayList = new ArrayList<>(tm.entrySet());
        Collections.sort(entryArrayList, Comparator.comparing(Map.Entry::getValue));
        screen.append("-------------------------------------------------\n");
        screen.append(analy.select_name+"�������˵����ܶ�Ϊ��\n");
        for (Map.Entry<String, Integer> entry : entryArrayList) {
            screen.append(entry.getKey() + "��" + entry.getValue()+"\n");
        }
    }
	}
}

public static void main(String[] args) {
	new textprocess();
}
}
