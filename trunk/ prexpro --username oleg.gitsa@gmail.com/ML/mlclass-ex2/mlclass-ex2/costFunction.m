function [J, grad] = costFunction(theta, X, y)
%COSTFUNCTION Compute cost and gradient for logistic regression
%   J = COSTFUNCTION(theta, X, y) computes the cost of using theta as the
%   parameter for logistic regression and the gradient of the cost
%   w.r.t. to the parameters.

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
%
% Note: grad should have the same dimensions as theta
%

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

J = J / m;
grad = grad ./ m;

% =============================================================

end
