<?php

namespace Drupal\stanford_news\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Block\BlockPluginInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 * Provides a 'Newsletter Signup' Block.
 *
 * @Block(
 *   id = "signup_block",
 *   admin_label = @Translation("Newsletter Signup"),
 *   category = @Translation("Newsletter Signup"),
 * )
 */
class SignupBlock extends BlockBase implements BlockPluginInterface {

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form = parent::blockForm($form, $form_state);

    $config = $this->getConfiguration();

    $form['form_action'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Stanford Mailing List Subscribe URL'),
      '#description' => $this->t('Example: Get a mailchimp url to be placed here'),
      '#default_value' => isset($config['form_action']) ? $config['form_action'] : '',
    ];

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
    parent::blockSubmit($form, $form_state);
    $values = $form_state->getValues();
    $this->configuration['form_action'] = $values['form_action'];
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    $config = $this->getConfiguration();
    if (isset($config['form_action']) && $config['form_action'] != '') {
      return [
        '#theme' => 'signup_block',
        '#configuration' => $config,
      ];
    } 
    else {
      return [];
    }
  }

}
