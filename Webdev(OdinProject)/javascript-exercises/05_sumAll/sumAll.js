const sumAll = function(num1, num2) {
    let bignum;
    let smallnum;
    let sum;
    if (num1>num2){
        bignum = num1;
        smallnum = num2;
    }
    else{
        bignum = num2;
        smallnum = num1;
    }
    for (let i=smallnum;i<=bignum;i++ ){
        sum+=i;
    }
    return sum;
};

// Do not edit below this line
module.exports = sumAll;
