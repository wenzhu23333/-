package Filemanager;

import javax.swing.*;
import javax.swing.text.DefaultCaret;
import javax.swing.tree.*;
import java.awt.*;
import java.awt.event.AdjustmentEvent;
import java.awt.event.AdjustmentListener;
import java.io.Serializable;
import java.util.Vector;

/*******************************************/
//����ļ����趨UI������ļ�
public class FileManagerUIview extends JPanel implements Serializable {
    private static final long serialVersionUID = 1L;
    JButton format = new JButton("��մ���");//��մ���
    JButton newDir = new JButton("�½��ļ���");//�½��ļ���
    JButton newFile = new JButton("�½��ļ�");//�½��ļ�
    JButton Delete = new JButton("ɾ���ļ�");//ɾ���ļ������ļ���
    JButton rename = new JButton("������");//�޸��ļ������ļ��е�����
    JButton open = new JButton("���ļ�");//���ļ�
    JButton close = new JButton("�ر��ļ�");//�ر��ļ�
    JScrollPane treeScorallPane = new JScrollPane();//�趨����ļ��нṹ�Ĺ��������
    JScrollPane editScorallPane = new JScrollPane();//�趨�Ҳ��޸Ľṹ�Ĺ��������
    JSplitPane treeAndEditPane = null;//�趨������������λ�����
    JSplitPane leftAndRightPane =null;//�趨���������λ�����
    JPanel buttonPane = null; //��ť���
    JPanel LeftPane = new JPanel();
    JPanel RightPane = new JPanel();

    JPanel colorPanel = new JPanel();

    JPanel RightPanelSouth = new JPanel();
    JPanel labelpanel = new JPanel();
    JLabel Block_display = new JLabel();
    JLabel Tracktracing = new JLabel();
    JLabel Block_size = new JLabel();
    JLabel Storage_size = new JLabel();
    JLabel Block_num = new JLabel();
    JLabel Track_num = new JLabel();
    JLabel Cmdoutput = new JLabel();
    JLabel Tips = new JLabel();
    JLabel TracktracingHelp = new JLabel();
    JLabel color = new JLabel();
    JLabel[] TrackNum = new JLabel[8];

    JPanel splitPanel = new JPanel();
    Font font = null;  //�趨�·�������
    Font font2 = null;
    //���������ļ��ṹ����Ҫ�����
    DefaultMutableTreeNode rootNode = null;//ĳ�����Ķ���
    DefaultTreeModel treeModel = null;//��������������ṹ����
    JTree tree = null;//������
    TreePath movePath = null;//�����õ�ĳ��Ŀ¼�����ļ������ṹ�е�·������
    JTextArea textArea = null;//����չʾĿ¼�����ļ�����Ϣ
    //end
    CmdOutput Cmd = new CmdOutput();
    DiskDisplay[] Disk = new DiskDisplay[128];
    DiskDisplay diskDisplay;
    JScrollPane jScrollPane1;
    JComboBox jComboBox = new JComboBox();
    JButton SelectTrack = new JButton("ѡ��ŵ�");


    Tracktracing tracktracing = null;
    public FileManagerUIview()
    {
        for (int i = 0;i<128;i++)
        {
           Disk[i] = new DiskDisplay();
        }

        diskDisplay = Disk[0];
        this.setLayout(null);
        //this.setBackground(Color.white);
        this.setVisible(true);
        this.setSize(Conf.FRAME_WIDTH,Conf.FRAME_LENGTH);
        buttonPane = new JPanel(new GridLayout(1, Conf.NUMBER_OF_BUTTONS));
        buttonPane.setBounds(0, 0, Conf.BUTTON_PANE_LENGTH, Conf.BUTTON_PANE_WIDTH);
        this.add(buttonPane);

        rootNode = new DefaultMutableTreeNode("Root", true);
        treeModel = new DefaultTreeModel(rootNode);
        tree = new JTree(treeModel);
        tree.setCellRenderer(new TreeCellRenderer());
        tree.getSelectionModel().setSelectionMode(TreeSelectionModel.SINGLE_TREE_SELECTION);

        textArea = new JTextArea();
        textArea.setEditable(false);
        textArea.setLineWrap(true);
        textArea.setBackground(Color.WHITE);
        treeScorallPane = new JScrollPane(tree);
        editScorallPane = new JScrollPane(textArea);

        treeAndEditPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,
                true, treeScorallPane, editScorallPane);
        treeAndEditPane.setBounds(0, Conf.BUTTON_PANE_WIDTH,
                Conf.TREE_AND_EDIT_PANE_LENGTH - 5, Conf.TREE_AND_EDIT_PANE_WIDTH - 50);
        treeAndEditPane.setDividerLocation(200);
        this.add(treeAndEditPane);
        font = new Font("����", Font.BOLD, 20);
        font2 = new Font("����",Font.BOLD,15);
        format.setFont(font);
        format.setOpaque(false);
        newDir.setFont(font);
        newDir.setOpaque(false);
        newFile.setFont(font);
        newFile.setOpaque(false);
        Delete.setFont(font);
        Delete.setOpaque(false);
        rename.setFont(font);
        rename.setOpaque(false);
        open.setFont(font);
        open.setOpaque(false);
        close.setFont(font);
        close.setOpaque(false);


        buttonPane.add(newFile);
        buttonPane.add(newDir);
        buttonPane.add(Delete);
        buttonPane.add(rename);
        buttonPane.add(open);
        buttonPane.add(close);
        buttonPane.add(format);



        RightPanelSouth = new JPanel(new GridLayout(2,1));


        splitPanel = new JPanel(new GridLayout(2,1));
        splitPanel.setBounds(1000,0,600,100);
        Tips.setText("Ӳ�̻�����Ϣ���£�  ��λ��Byte��");
        Tips.setFont(font2);
        splitPanel.add(Tips);
        Storage_size.setText("�ڴ��С��"+Conf.MEMORY_SIZE);
        Storage_size.setFont(font2);
        Block_num.setText("�̿�������"+Conf.BLOCK_NUM);
        Block_size.setFont(font2);
        Block_size.setText("�̿��С��"+Conf.BLOCK_SIZE);
        Block_num.setFont(font2);
        Track_num.setText("�ŵ�������"+Conf.Track_num);
        Track_num.setFont(font2);
        labelpanel = new JPanel(new GridLayout(2,4));
        labelpanel.setBounds(1000,0,400,50);

        color.setText("��ǰ�ļ���ɫ��");
        color.setFont(font2);
        color.setBounds(1460,0,200,50);
        this.add(color);
        colorPanel.setBounds(1500,50,50,50);
        //colorPanel.setBackground(Color.BLACK);
        this.add(colorPanel);

        labelpanel.add(Track_num);
        labelpanel.add(Block_size);
        labelpanel.add(Block_num);
        labelpanel.add(Storage_size);
        splitPanel.add(labelpanel);
        //RightPane.add(splitPanel,BorderLayout.NORTH);

        this.add(splitPanel);
        for (int i = 0;i<8;i++)
        {
            TrackNum[i] = new JLabel(String.valueOf(i*16));
            TrackNum[i].setBounds(1020+i*64-5,795,50,50);
            this.add(TrackNum[i]);
        }

        TracktracingHelp.setFont(font2);
        Block_display.setFont(font2);
        Tracktracing.setFont(font2);
        Block_display.setForeground(Color.red);
        TracktracingHelp.setForeground(Color.black);
        Tracktracing.setForeground(Color.red);
        TracktracingHelp.setText("(�·���ͷ��������Ϊ�ŵ���)");
        Block_display.setText("�̿�ʹ�ã�");
        Tracktracing.setText("�ŵ�׷�٣�");
        Block_display.setBounds(1000,100,200,50);
        TracktracingHelp.setBounds(1100,550,300,50);
        Tracktracing.setBounds(1000,550,100,50);
        this.add(TracktracingHelp);
        this.add(Block_display);
        this.add(Tracktracing);
        Cmdoutput.setFont(font2);
        Cmdoutput.setForeground(Color.red);
        Cmdoutput.setText("�����������");
        Cmdoutput.setBounds(1000,350,600,50);
        //ÿ���Զ����µ����һ��
        this.add(Cmdoutput);
        JScrollPane jScrollPane = new JScrollPane(Cmd);
        jScrollPane.setBounds(1000,400,600,150);
        diskDisplay.setPreferredSize(new Dimension(580,290));
        jScrollPane1 = new JScrollPane(diskDisplay);
        jScrollPane1.setBounds(1000,150,600,200);
        this.add(jScrollPane1);
        //������δ����ǽ����Ӱ�����⣬����û�����ϣ���diskdisplay����ʹ��super�ͽ��������
        /*JScrollBar jScrollBar = jScrollPane1.getVerticalScrollBar();
        jScrollBar.addAdjustmentListener(new AdjustmentListener() {
            @Override
            public void adjustmentValueChanged(AdjustmentEvent e) {
                diskDisplay.repaint();
            }
        });*/
        this.add(jScrollPane);
        this.setOpaque(true);

        for(int i = 0;i<128;i++)
        {
            jComboBox.addItem(i);
        }
        jComboBox.setBounds(1100,110,100,25);
        this.add(jComboBox);
        SelectTrack.setBounds(1225,110,100,25);
        this.add(SelectTrack);

        Vector<Integer> a = new Vector<Integer>();
        Vector<Integer> b = new Vector<Integer>();
        tracktracing = new Tracktracing(a,b);
        JScrollPane jScrollPane2 = new JScrollPane(tracktracing);
        jScrollPane2.setBounds(1020,600,530,180);
        tracktracing.setPreferredSize(new Dimension(512,5000));
        this.add(jScrollPane2);

    }


    public void paint(Graphics g)
    {
        super.paint(g);
        Graphics2D g2 = (Graphics2D)g;
        g2.setColor(Color.black);
        g2.setStroke(new BasicStroke(3.0f));
        g2.drawLine(1020,800,1550,800);
        g2.drawLine(1540,790,1550,800);
        g2.drawLine(1540,810,1550,800);
        for (int i = 0;i<=7;i++)
        {
            g2.setStroke(new BasicStroke(3.0f));
            g2.drawLine(1020+i*64,790,1020+i*64,800);
            g2.setStroke(new BasicStroke(1.0f));
            for (int j = 1;j<16;j++)
            {
                g2.drawLine(1020+i*64+j*4,795,1020+i*64+j*4,800);
            }
        }

    }

    class TreeCellRenderer extends DefaultTreeCellRenderer implements Serializable {
        private static final long serialVersionUID = 1L;
        public Component getTreeCellRendererComponent(JTree tree, Object value, boolean sel, boolean expanded, boolean leaf, int row, boolean hasFocus) {
            super.getTreeCellRendererComponent(tree, value, sel, expanded, leaf, row, hasFocus);
            DefaultMutableTreeNode node = (DefaultMutableTreeNode)value;
            if (node.getAllowsChildren()) {
                if (expanded) {
                    this.setIcon(new ImageIcon("folder_open.png"));
                } else {
                    this.setIcon(new ImageIcon("folder_close.png"));
                }
            } else {
                this.setIcon(new ImageIcon("file.png"));
            }
            if (node.isRoot()) {
                this.setIcon(new ImageIcon("root.png"));
            }
            return this;
        }
    }




}
