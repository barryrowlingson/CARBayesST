\name{ST.CARlocalised}
\alias{ST.CARlocalised}


\title{
    Fit a spatio-temporal generalised linear mixed model to data, with a spatio-temporal
    autoregressive process and a piecewise constant intercept term.
}

\description{
    Fit a spatio-temporal generalised linear mixed model to areal unit data, where the response
    variable can be binomial or Poisson. The linear predictor is modelled by known 
    covariates, a vector of random effects and a piecewise constant intercept process. The 
    random effects follow the multivariate first order autoregressive time series process
    proposed by Rushworth et al.(2014)., and are the same as those used in the ST.CARar() function.
    The piecewise constant intercept component allows neighbouring areal units to have very
    different values if they are assigned to a different intercept component. This model allows
    for localised smoothness as some pairs of neighbouring areas or time periods can have similar 
    values while other neighbouring pairs have different values. This is a spatio-temopral extension 
    of Lee and Sarran (2015), and furter details are given in the vignette accompanying this package. 
    Inference is conducted in a Bayesian setting using Markov chain Monte Carlo (McMC) simulation. 
}

\usage{
    ST.CARlocalised(formula, family, data=NULL,  G, trials=NULL, W, burnin, n.sample, 
    thin=1, prior.mean.beta=NULL, prior.var.beta=NULL, prior.delta=NULL, 
    prior.tau2=NULL, verbose=TRUE)
}


%- maybe also 'usage' for other objects documented here.
\arguments{
    \item{formula}{
        A formula for the covariate part of the model using the syntax of the
        lm() function. Offsets can be included here using the offset() function. 
        The response and each covariate should be vectors of length (KT)*1, where
        K is the number of spatial units and T is the number of time periods. Each
        vector should be ordered so that the first K data points are the set of all
        K spatial locations at time 1, the next K are the set of spatial points for
        time 2 and so on.
    }
    \item{family}{
        One of either `binomial' or `poisson', which respectively specify a 
        binomial likelihood model with a logistic link function, or a Poisson 
        likelihood model with a log link function. 
    }
    \item{data}{
        An optional data.frame containing the  variables in the formula.
    }
    \item{G}{
        The maximum number of distinct intercept terms (clusters) to allow in the model.
    }
    \item{trials}{
        A vector the same length as the response containing the total number of trials 
        for each area and time period. Only used if family=`binomial'. 
    }
        \item{W}{
        A K by K neighbourhood matrix (where K is the number of spatial units). 
        Typically a binary specification is used, where the jkth element equals one
        if areas (j, k) are spatially close (e.g. share a common border) and is zero 
        otherwise. The matrix can be non-binary, but each row must contain at least 
        one non-zero entry.
    }  
        \item{burnin}{
        The number of McMC samples to discard as the burnin period.
    }
        \item{n.sample}{
        The number of McMC samples to generate.
    }
        \item{thin}{
        The level of thinning to apply to the McMC samples to reduce their temporal 
        autocorrelation. Defaults to 1.
    }
        \item{prior.mean.beta}{
        A vector of prior means for the regression parameters beta (Gaussian priors are 
        assumed). Defaults to a vector of zeros.
    }
        \item{prior.var.beta}{
        A vector of prior variances for the regression parameters beta (Gaussian priors 
        are assumed). Defaults to a vector with values 1000.
    }  
        \item{prior.delta}{
        The prior maximum for the cluster smoothing parameter delta. Defaults to 10.  
    }
        \item{prior.tau2}{
        The prior shape and scale in the form of c(shape, scale) for an Inverse-Gamma(shape, scale) 
        prior for the random effect variance tau2. Defaults to c(0.001, 0.001).  
    }
        \item{verbose}{
        Logical, should the function update the user on its progress.  
    }
        }


\value{
    \item{summary.results }{A summary table of the parameters.}
    \item{samples }{A list containing the McMC samples from the model.}
    \item{fitted.values }{A vector of fitted values for each area and time period.}
    \item{residuals }{A vector of residuals for each area and time period.}
    \item{modelfit }{Model fit criteria including the Deviance Information Criterion 
                     (DIC), the effective number of parameters in the model (p.d), and the Log 
                     Marginal Predictive Likelihood (LMPL).}
    \item{accept }{The acceptance probabilities for the parameters.}
    \item{localised.structure }{A vector giving the posterior median of which intercept component
    (group) each data point is in.}
    \item{formula }{The formula for the covariate and offset part of the model.}
    \item{model }{A text string describing the model fit.}
    \item{X }{The design matrix of covariates.}
}

\references{
    Lee, D and Sarran, C  (2015). Controlling for unmeasured confounding and spatial 
    misalignment in long-term air pollution and health studies, Environmetrics, to appear.

    Rushworth, A., D. Lee, and R. Mitchell (2014). A spatio-temporal model for estimating
    the long-term effects of air pollution on respiratory hospital admissions in Greater
    London. Spatial and Spatio-temporal Epidemiology 10, 29-38.
}

\author{
    Duncan Lee
}




\examples{
##################################################
#### Run the model on simulated data on a lattice
##################################################
#### set up the regular lattice    
x.easting <- 1:10
x.northing <- 1:10
Grid <- expand.grid(x.easting, x.northing)
K <- nrow(Grid)
T <- 10
N.all <- T * K
    
#### set up spatial neighbourhood matrix W
W <-array(0, c(K,K))
    for(i in 1:K)
    {
        for(j in 1:K)
        {
        temp <- (Grid[i,1] - Grid[j,1])^2 + (Grid[i,2] - Grid[j,2])^2
        if(temp==1)  W[i,j] <- 1 
        }    
    }


#### Simulate the elements in the linear predictor and the data
Q.W <- 0.99 * (diag(apply(W, 2, sum)) - W) + 0.01 * diag(rep(1,K))
Q.W.inv <- solve(Q.W)
phi.temp <- mvrnorm(n=1, mu=rep(0,K), Sigma=(0.1 * Q.W.inv))
phi <- phi.temp
    for(i in 2:T)
    {
    phi.temp2 <- mvrnorm(n=1, mu=(0.8 * phi.temp), Sigma=(0.1 * Q.W.inv))
    phi.temp <- phi.temp2
    phi <- c(phi, phi.temp)
    }
jump <- rep(c(rep(3, 70), rep(4, 30)),T)
LP <- jump + phi
fitted <- exp(LP)
Y <- rpois(n=N.all, lambda=fitted)

#### Run the model     
\dontrun{model1 <- ST.CARlocalised(formula=Y~1, family="poisson", G=3, W=W, burnin=10000,
n.sample=50000)}
}
