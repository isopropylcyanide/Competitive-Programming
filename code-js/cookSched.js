

function f(a,i,len,k,state){
  // We cannot change the state of a[i] if k is zero
  if (k === 0 && a[i] != state)
    return Infinity;

  // The first element is a sequence of length 1
  if (i === 0)
    return 1;

  var oppositeState = state == 0 ? 1 : 0;

  if (a[i] == state){
    // Starting a new sequence
    if (len === 1){
      var best = Infinity;

      for (var l=1; l<i+1; l++)
        best = Math.min( best, f(a, i-1, l, k, oppositeState) );

      return best;

    // Adding to a sequence (len > 1)
    } else {
      return Math.max( len, f(a, i-1, len-1, k, state) );
    }

  // a[i] does not equal state
  } else if (k > 0) {
    // Starting a new sequence
    if (len === 1){
      var best = Infinity;

      for (var l=1; l<i+1; l++)
        best = Math.min( best, f(a, i-1, l, k-1, oppositeState) );

      return best;

    // Adding to a sequence (len > 1)
    } else {
      return Math.max( len, f(a, i-1, len-1, k-1, state) );
    }

  // If k is zero, we cannot change the state of a[i]
  } else {
    return Infinity;
  }
}

function g(arr,k){
  var best = Infinity;

  for (var l=1; l<=2*arr.length; l++)
    best = Math.min(best, f(arr, arr.length-1, Math.ceil(l/2), k, l % 2));

  return best;
}

process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function main() {
    var t = parseInt(readLine());
    for (var i = 0; i < t; i++){
        var n_temp = readLine().split(' ');
        var n = parseInt(n_temp[0]);
        var k = parseInt(n_temp[1]);
        var s = readLine();
        console.log(g(s, k))
    }

}
