(function ($) {

  /**
   * Set active class on Views AJAX filter
   * on selected category
   */
  Drupal.behaviors.EarthMatters = {
    attach: function (context, settings) {

      var view = $('.earth-matters-listing.news-list');

      function setFilter(value, filter) {
        if ($(filter).attr('multiple')) {
          var existingValues = $(filter).val();

          console.log(existingValues);

          if (existingValues) {
            var i = existingValues.indexOf(value);

            if (i !== -1) {
              delete existingValues[i];
            }
            else {
              existingValues.push(value);
            }
            value = existingValues;
          }
          else {
            value = [value];
          }

          if (value.length) {
            value = cleanArray(value);
          }
        }

        filter.val(value);
        $(filter).trigger('change');

        refreshViews();
      }

      function cleanString(string) {
        string = string.replace(/[^a-zA-Z0-9]+/g, '-').toLowerCase().replace(' ', '-');

        while (string.indexOf('--') != -1) {
          string = string.replace('--', '-');
        }

        return string;
      }

      function cleanArray(actual) {
        var newArray = [];
        for (var i = 0; i < actual.length; i++) {
          if (actual[i]) {
            newArray.push(actual[i]);
          }
        }
        return newArray;
      }

      function refreshViews() {
        var views = settings.views.ajaxViews;

        $.each(views, function (i, view) {
          var dom_id = view.view_dom_id;
          var selector = '.js-view-dom-id-' + dom_id;
          settings.views.ajaxViews['views_dom_id:' + dom_id].view_args = $(selector).find('select').val().join('+');
          $(selector).triggerHandler('RefreshView');
        });
      }

      function setFilterClick(element, view) {
        if ($(element).hasClass('filterClickProcessed')) {
          return;
        }

        $(element).on('click', function (e) {
          e.preventDefault();
          $(this).toggleClass('active');

          var tid = $(this).attr('data-tid');
          if (!tid) {
            tid = $(this).attr('rel');
          }
          var filter = $(view).find('select');

          setPushState($(this).text());


          setFilter(tid, filter);
        }).addClass('filterClickProcessed');
      }

      function setPushState(string) {
        var current_path = window.location.href;
        string = cleanString(string);
        if (current_path.indexOf(string) == -1) {
          current_path = current_path + '/' + string;
        }
        else {
          current_path = current_path.replace('/' + string, '');
        }

        history.pushState(null, null, current_path);
      }

      $(view).find('.filter-tab a, .masonry-block__tags .tag-item').each(function () {
        setFilterClick(this, view);
      });
    }
  };

  function setActives() {
    // var view = $('.earth-matters-listing.news-list');
    // $(view).find('.filter-tab a').removeClass('active');
    // var topics = $(view).find('select').val();
    //
    // $(topics).each(function (i, value) {
    //   $(view).find('a[data-tid="' + value + '"]').addClass('active');
    //   $(view).find('a[rel="' + value + '"]').addClass('active');
    // });
  }

  jQuery(document).ajaxComplete(setActives);
  setActives();


})(jQuery);
