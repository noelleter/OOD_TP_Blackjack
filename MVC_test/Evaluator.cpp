//
//  Evaluator.cpp
//  MVC_test
//
//  Created by 김노은 on 30/11/2019.
//  Copyright © 2019 Noeun-Kim. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <list>

#include "Dealer.h"
#include "Player.h"
#include "Hand.h"
#include "Deck.h"
#include "Card.h"

using namespace std;

class Evaluator{
private:
    map<string, Player> playerMap;
    Dealer dealer;
    
public:
    // 생성자
    Evaluator(){}
    Evaluator(map<string, Player> &playerMap){
        this->playerMap = playerMap;
        dealer = *new Dealer();
        dealCardToPlayers();
    }
    
    // 공개 함수
    void dealCardToPlayers() {
        std::map<string, Player>::iterator it;
        Player player;
        for (it=playerMap.begin(); it!=playerMap.end(); ++it){
            cout << "!! '" << it->first << "' 초기 카드 두 장 Draw." << endl;
            player = playerMap[it->first];
            player.hitCard();
            player.hitCard();
        }
        cout << endl;
    }
    
    void start(){
        int deal_score = 0;
        std::map<string, Player>::iterator it;
        std::list<Card>::iterator it_L;
        Player player;

        cout << "! 게임을 시작합니다. " << endl;
        
        deal_score = dealer.getDealerScore();
        
        for (it=playerMap.begin(); it!=playerMap.end(); ++it){
    
            player = playerMap[it->first];
            
            Hand* pHand = player.getHand();
            cout << "HAND 확인 " << pHand->getHandList()->size() << endl;
            list<Card>* pList = pHand->getHandList();
            
            cout << "MAP 확인 " << playerMap.size() << endl;
            
            
            int total = 0;
            int check = 0;
            /*
            for (it_L=pList.begin(); it_L!=pList.end(); ++it_L){
                total += it_L->Rank();
                cout << check << endl;
                check++;
            }*/
            
            cout << "! 합계는 " << total << endl;
            
            
            if(total == 21){
                cout << it->first << "가 이겼습니다 !" << endl;
            }
            else if(total > 21) {
                cout << it->first << "가 졌습니다 !" << endl;
            }
            else {
                if (deal_score < total){
                    cout << it->first << "가 이겼습니다 !" << endl;
                    player.setBalance(player.Balance()+2*player.CurrBet());
                }
                else if(total == deal_score) {
                    cout << it->first << "가 졌습니다 !" << endl;
                }
                else {
                    cout << it->first << "가 졌습니다 !" << endl;
                }
            }
        }
    
    }
};
