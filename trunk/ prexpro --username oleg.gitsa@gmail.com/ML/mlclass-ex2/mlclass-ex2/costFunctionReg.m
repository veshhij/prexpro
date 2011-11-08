function [J, grad] = costFunctionReg(theta, X, y, lambda)
%COSTFUNCTIONREG Compute cost and gradient for logistic regression with regularization
%   J = COSTFUNCTIONREG(theta, X, y, lambda) computes the cost of using
%   theta as the parameter for regularized logistic regression and the
%   gradient of the cost w.r.t. to the parameters. 

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta

x_hip = 0;
ts = length( theta( :, 1 ) );

for iter = 1:m
    x_hip = sigmoid( X( iter, : ) * theta );
    J = J + ( ( - y( iter ) ) * log( x_hip ) - ( 1 - y( iter ) ) * log( 1 - x_hip ) );
    for j = 1:ts
        r = x_hip - y( iter );
        grad( j, 1 ) = grad( j, 1 ) + r * X( iter, j );
    end
end

theta_sum = 0;
theta_reg = zeros(size(theta));

for ti = 1:ts
    if ti > 1
        theta_sum = theta_sum + theta( ti, 1 ) * theta( ti, 1 );
        theta_reg( ti, 1 ) = lambda * theta( ti, 1 );
    end 
end

theta_sum = theta_sum * lambda / ( 2 * m );


J = J / m + theta_sum;

grad = grad .+ theta_reg;
grad = grad ./ m;





% =============================================================

end
