clear ; close all; clc

hold on;

v = [2:5:50];

semilogy( v .^ 2, 'k' );
semilogy( v.^2 .* log( v ), 'r' );
semilogy( v .^ log( v ), 'm' );
semilogy( 2 .^ v, 'b' );
semilogy( 2 .^ ( 2 .^ v ), 'g' );

%plot( 2 .^ ( 2 .^ v ), 'g' );
%plot( v.^2 .* log( v ), 'r' );
%plot( 2 .^ v, 'b' );
%plot( v .^ 2, 'k' );
%plot( v .^ log( v ), 'm' );

hold off;
