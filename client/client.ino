#define SERVER
 /* Team Members: QB (qb484), BB (), TH (th28794), CW (ciw279) 
 *                                                                                                                                                                                                                                                                                                                                 
 * EEEEEEEEEEEEEEEEEEEEEE                                                                                         444444444       000000000      222222222222222    
 * E::::::::::::::::::::E                                                                                        4::::::::4     00:::::::::00   2:::::::::::::::22  
 * E::::::::::::::::::::E                                                                                       4:::::::::4   00:::::::::::::00 2::::::222222:::::2 
 * EE::::::EEEEEEEEE::::E                                                                                      4::::44::::4  0:::::::000:::::::02222222     2:::::2 
 *   E:::::E       EEEEEErrrrr   rrrrrrrrr   rrrrr   rrrrrrrrr      ooooooooooo   rrrrr   rrrrrrrrr           4::::4 4::::4  0::::::0   0::::::0            2:::::2 
 *   E:::::E             r::::rrr:::::::::r  r::::rrr:::::::::r   oo:::::::::::oo r::::rrr:::::::::r         4::::4  4::::4  0:::::0     0:::::0            2:::::2 
 *   E::::::EEEEEEEEEE   r:::::::::::::::::r r:::::::::::::::::r o:::::::::::::::or:::::::::::::::::r       4::::4   4::::4  0:::::0     0:::::0         2222::::2  
 *   E:::::::::::::::E   rr::::::rrrrr::::::rrr::::::rrrrr::::::ro:::::ooooo:::::orr::::::rrrrr::::::r     4::::444444::::4440:::::0 000 0:::::0    22222::::::22   
 *   E:::::::::::::::E    r:::::r     r:::::r r:::::r     r:::::ro::::o     o::::o r:::::r     r:::::r     4::::::::::::::::40:::::0 000 0:::::0  22::::::::222     
 *   E::::::EEEEEEEEEE    r:::::r     rrrrrrr r:::::r     rrrrrrro::::o     o::::o r:::::r     rrrrrrr     4444444444:::::4440:::::0     0:::::0 2:::::22222        
 *   E:::::E              r:::::r             r:::::r            o::::o     o::::o r:::::r                           4::::4  0:::::0     0:::::02:::::2             
 *   E:::::E       EEEEEE r:::::r             r:::::r            o::::o     o::::o r:::::r                           4::::4  0::::::0   0::::::02:::::2             
 * EE::::::EEEEEEEE:::::E r:::::r             r:::::r            o:::::ooooo:::::o r:::::r                           4::::4  0:::::::000:::::::02:::::2       222222
 * E::::::::::::::::::::E r:::::r             r:::::r            o:::::::::::::::o r:::::r                         44::::::44 00:::::::::::::00 2::::::2222222:::::2
 * E::::::::::::::::::::E r:::::r             r:::::r             oo:::::::::::oo  r:::::r                         4::::::::4   00:::::::::00   2::::::::::::::::::2
 * EEEEEEEEEEEEEEEEEEEEEE rrrrrrr             rrrrrrr               ooooooooooo    rrrrrrr                         4444444444     000000000     22222222222222222222
 * 
 * PPPPPPPPPPPPPPPPP                                                                                                              tttt          
 * P::::::::::::::::P                                                                                                          ttt:::t          
 * P::::::PPPPPP:::::P                                                                                                         t:::::t          
 * PP:::::P     P:::::P                                                                                                        t:::::t          
 *   P::::P     P:::::Paaaaaaaaaaaaayyyyyyy           yyyyyyy mmmmmmm    mmmmmmm       eeeeeeeeeeee    nnnn  nnnnnnnn    ttttttt:::::ttttttt    
 *   P::::P     P:::::Pa::::::::::::ay:::::y         y:::::ymm:::::::m  m:::::::mm   ee::::::::::::ee  n:::nn::::::::nn  t:::::::::::::::::t    
 *   P::::PPPPPP:::::P aaaaaaaaa:::::ay:::::y       y:::::ym::::::::::mm::::::::::m e::::::eeeee:::::een::::::::::::::nn t:::::::::::::::::t    
 *   P:::::::::::::PP           a::::a y:::::y     y:::::y m::::::::::::::::::::::me::::::e     e:::::enn:::::::::::::::ntttttt:::::::tttttt    
 *   P::::PPPPPPPPP      aaaaaaa:::::a  y:::::y   y:::::y  m:::::mmm::::::mmm:::::me:::::::eeeee::::::e  n:::::nnnn:::::n      t:::::t          
 *   P::::P            aa::::::::::::a   y:::::y y:::::y   m::::m   m::::m   m::::me:::::::::::::::::e   n::::n    n::::n      t:::::t          
 *   P::::P           a::::aaaa::::::a    y:::::y:::::y    m::::m   m::::m   m::::me::::::eeeeeeeeeee    n::::n    n::::n      t:::::t          
 *   P::::P          a::::a    a:::::a     y:::::::::y     m::::m   m::::m   m::::me:::::::e             n::::n    n::::n      t:::::t    tttttt
 * PP::::::PP        a::::a    a:::::a      y:::::::y      m::::m   m::::m   m::::me::::::::e            n::::n    n::::n      t::::::tttt:::::t
 * P::::::::P        a:::::aaaa::::::a       y:::::y       m::::m   m::::m   m::::m e::::::::eeeeeeee    n::::n    n::::n      tt::::::::::::::t
 * P::::::::P         a::::::::::aa:::a     y:::::y        m::::m   m::::m   m::::m  ee:::::::::::::e    n::::n    n::::n        tt:::::::::::tt
 * PPPPPPPPPP          aaaaaaaaaa  aaaa    y:::::y         mmmmmm   mmmmmm   mmmmmm    eeeeeeeeeeeeee    nnnnnn    nnnnnn          ttttttttttt  
 *                                        y:::::y                                                                                               
 *                                       y:::::y                                                                                                
 *                                      y:::::y                                                                                                 
 *                                     y:::::y                                                                                                  
 *                                    yyyyyyy                                                                                                   
 * 
 *                                                                                                                                          dddddddd
 * RRRRRRRRRRRRRRRRR                                                               iiii                                                     d::::::d
 * R::::::::::::::::R                                                             i::::i                                                    d::::::d
 * R::::::RRRRRR:::::R                                                             iiii                                                     d::::::d
 * RR:::::R     R:::::R                                                                                                                     d:::::d 
 *   R::::R     R:::::R    eeeeeeeeeeee       qqqqqqqqq   qqqqquuuuuu    uuuuuu  iiiiiiirrrrr   rrrrrrrrr       eeeeeeeeeeee        ddddddddd:::::d 
 *   R::::R     R:::::R  ee::::::::::::ee    q:::::::::qqq::::qu::::u    u::::u  i:::::ir::::rrr:::::::::r    ee::::::::::::ee    dd::::::::::::::d 
 *   R::::RRRRRR:::::R  e::::::eeeee:::::ee q:::::::::::::::::qu::::u    u::::u   i::::ir:::::::::::::::::r  e::::::eeeee:::::ee d::::::::::::::::d 
 *   R:::::::::::::RR  e::::::e     e:::::eq::::::qqqqq::::::qqu::::u    u::::u   i::::irr::::::rrrrr::::::re::::::e     e:::::ed:::::::ddddd:::::d 
 *   R::::RRRRRR:::::R e:::::::eeeee::::::eq:::::q     q:::::q u::::u    u::::u   i::::i r:::::r     r:::::re:::::::eeeee::::::ed::::::d    d:::::d 
 *   R::::R     R:::::Re:::::::::::::::::e q:::::q     q:::::q u::::u    u::::u   i::::i r:::::r     rrrrrrre:::::::::::::::::e d:::::d     d:::::d 
 *   R::::R     R:::::Re::::::eeeeeeeeeee  q:::::q     q:::::q u::::u    u::::u   i::::i r:::::r            e::::::eeeeeeeeeee  d:::::d     d:::::d 
 *   R::::R     R:::::Re:::::::e           q::::::q    q:::::q u:::::uuuu:::::u   i::::i r:::::r            e:::::::e           d:::::d     d:::::d 
 * RR:::::R     R:::::Re::::::::e          q:::::::qqqqq:::::q u:::::::::::::::uui::::::ir:::::r            e::::::::e          d::::::ddddd::::::dd
 * R::::::R     R:::::R e::::::::eeeeeeee   q::::::::::::::::q  u:::::::::::::::ui::::::ir:::::r             e::::::::eeeeeeee   d:::::::::::::::::d
 * R::::::R     R:::::R  ee:::::::::::::e    qq::::::::::::::q   uu::::::::uu:::ui::::::ir:::::r              ee:::::::::::::e    d:::::::::ddd::::d
 * RRRRRRRR     RRRRRRR    eeeeeeeeeeeeee      qqqqqqqq::::::q     uuuuuuuu  uuuuiiiiiiiirrrrrrr                eeeeeeeeeeeeee     ddddddddd   ddddd
 *                                                     q:::::q                                                                                      
 *                                                     q:::::q                                                                                      
 *                                                    q:::::::q                                                                                     
 *                                                    q:::::::q                                                                                     
 *                                                    q:::::::q                                                                                     
 *                                                    qqqqqqqqq  
 * 
 * 
 * Lab 1
 */
