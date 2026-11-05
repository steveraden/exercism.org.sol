namespace hellmath {
// account types: `troll`, `guest`, `user`, and `mod`.
enum class AccountStatus{
    troll,
    guest,
    user,
    mod
};
// permission types: `read`, `write`, and `remove`.
enum class Action{
    read,
    write,
    remove
};
    
bool display_post(AccountStatus poster_status, AccountStatus viewer_status) {
    if (poster_status == AccountStatus::troll) {
        if (viewer_status ==AccountStatus::troll ){
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}
    
bool permission_check(Action action, AccountStatus account_status) {
    switch (action){
        case Action::read:
            return true;
        case Action::write:
            if (account_status == AccountStatus::guest){
                return false;
            } else {
                return true;
            }
        case Action::remove:
            if (account_status == AccountStatus::mod){
                return true;
            } else {
                return false;
            }
    }
    return false;
}

// checks if two players can join the same game. 
bool valid_player_combination(AccountStatus player1_status,  AccountStatus player2_status) {
    switch (player1_status) {
        case AccountStatus::user:
        case AccountStatus::mod:
              if (player2_status == AccountStatus::guest ||
                  player2_status == AccountStatus::troll
                  ){
                return false;
            } else {
                return true;
            }
        case AccountStatus::guest:
            return false;
        case AccountStatus::troll:
            if (player2_status == AccountStatus::troll ){
                return true;
            } else {
                return false;
            }  
    }    
    return false;
}
     
// if and only if the first account has a strictly higher priority than the second.
bool has_priority(AccountStatus player1_status,  AccountStatus player2_status) {
    if  (player1_status > player2_status){
        return true;
    } else {
        return false;
    }
}
    
}  // namespace hellmath
