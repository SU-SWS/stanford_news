!function(t){var a={};function n(e){if(a[e])return a[e].exports;var r=a[e]={i:e,l:!1,exports:{}};return t[e].call(r.exports,r,r.exports,n),r.l=!0,r.exports}n.m=t,n.c=a,n.d=function(e,r,t){n.o(e,r)||Object.defineProperty(e,r,{enumerable:!0,get:t})},n.r=function(e){"undefined"!=typeof Symbol&&Symbol.toStringTag&&Object.defineProperty(e,Symbol.toStringTag,{value:"Module"}),Object.defineProperty(e,"__esModule",{value:!0})},n.t=function(r,e){if(1&e&&(r=n(r)),8&e)return r;if(4&e&&"object"==typeof r&&r&&r.__esModule)return r;var t=Object.create(null);if(n.r(t),Object.defineProperty(t,"default",{enumerable:!0,value:r}),2&e&&"string"!=typeof r)for(var a in r)n.d(t,a,function(e){return r[e]}.bind(null,a));return t},n.n=function(e){var r=e&&e.__esModule?function(){return e.default}:function(){return e};return n.d(r,"a",r),r},n.o=function(e,r){return Object.prototype.hasOwnProperty.call(e,r)},n.p="",n(n.s=0)}([function(e,r,t){"use strict";t.r(r);t(1)},function(e,r,t){window.Drupal.behaviors.stanford_news={attach:function(d){!function(e){e(".news-social-media",d).prepend('<div class="widget-wrapper-print"><a href="" class="share-print su-news-header__social-print"><i class="fas fa-printer" aria-hidden="true"></i><span>'+Drupal.t("Print Article")+"</span></a></div>"),e(".news-social-media",d).prepend('<div class="widget-wrapper-forward"><a href="" class="share-forward su-news-header__social-forward"><i class="fas fa-envelope" aria-hidden="true"></i><span>'+Drupal.t("Forward Email")+"</span></a></div>"),e(".news-social-media",d).prepend('<div class="widget-wrapper-linkedin"><a href="" class="share-linkedin su-news-header__social-linkedin"><i aria-hidden="true"></i><span>'+Drupal.t("Stanford LinkedIn")+"</span></a></div>"),e(".news-social-media",d).prepend('<div class="widget-wrapper-twitter"><a href="" class="share-twitter su-news-header__social-twitter"><i aria-hidden="true"></i><span>'+Drupal.t("Stanford Twitter")+"</span></a></div>"),e(".news-social-media",d).prepend('<div class="widget-wrapper-fb"><a href="" class="share-fb su-news-header__social-facebook"><i aria-hidden="true"></i><span>'+Drupal.t("Stanford Facebook")+"</span></a></div>");var r=window.location,t=e('div[property="dc:title"] h1',d).text(),a=e(".share-sub",d).text(),n="https://twitter.com/intent/tweet?url="+encodeURI(r)+"&text="+t+" "+a,i="http://www.facebook.com/sharer.php?u="+r+"&display=popup",s="https://www.linkedin.com/shareArticle?mini=true&url="+r+"&title="+t+"&summary="+a,o="mailto:?subject="+document.title+"&body="+encodeURI(document.location);e(".share-fb",d).attr({href:i}),e(".share-twitter",d).attr({href:n}),e(".share-linkedin",d).attr({href:s}),e(".share-forward",d).attr({href:o}),e(".share-print",d).attr({onclick:"window.print();return false;"})}(jQuery)}}}]);
//# sourceMappingURL=news-node.behaviors.js.map