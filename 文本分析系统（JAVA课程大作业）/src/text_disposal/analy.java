package text_disposal;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.nio.channels.SelectableChannel;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

public class analy extends JFrame implements ActionListener{  
	public static String select_name;
	JButton yes=new JButton("ȷ��");
	JComboBox comboBox=new JComboBox(input.name); 
    public analy(){  
        this.setTitle("ѡ��鿴���ܶȵ�����");  
        this.setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        this.setBounds(100,100,250,100);  
        JPanel contentPane=new JPanel();  
        contentPane.setBorder(new EmptyBorder(5,5,5,5));  
        this.setContentPane(contentPane);  
        JLabel label=new JLabel("��ѡ������:");  
        contentPane.add(label);  
        contentPane.add(comboBox);  
        this.setVisible(true);  
        contentPane.add(yes);
        yes.addActionListener(this);
        this.setSize(400,200);
    }

	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource()==yes)
		{
			analy.select_name=(String)comboBox.getSelectedItem();
			this.dispose();
		}
	}



}
