(function ($) {

  /**
   * Set active class on Views AJAX filter
   * on selected category
   */
  Drupal.behaviors.EarthMatters = {
    attach: function (context, settings) {

      function setFilter(value, filter) {

        if ($(filter).attr('multiple')) {
          var existingValues = $(filter).val();

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
        $(filter).closest('form').find('input.form-submit').trigger('click');
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


      var view = $('.earth-matters-listing.news-list');

      $(view).find('.filter-tab a, .masonry-block__tags .tag-item').each(function () {
        setFilterClick(this, view);
      });
    }
  };

  function setActives() {
    var view = $('.earth-matters-listing.news-list');
    $(view).find('.filter-tab a').removeClass('active');
    var topics = $(view).find('select').val();

    $(topics).each(function (i, value) {
      $(view).find('a[data-tid="' + value + '"]').addClass('active');
      $(view).find('a[rel="' + value + '"]').addClass('active');
    });
  }

  jQuery(document).ajaxComplete(setActives);
  setActives();


})(jQuery);